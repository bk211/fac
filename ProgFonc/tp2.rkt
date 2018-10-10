#lang racket
(require racket/trace)
(define (plat L)
  (if (empty? L) '()
      (if (list? (first L)) (append (plat (first L)) (plat(rest L)))
          (append (list (first L)) (plat(rest L))))))
                         
            
;(trace plat)
;(plat '(3 2 () (2 (1 () ))))

(define (fusion L1 L2)
  (if (empty? L2) L1
      (cons (first L2) (fusion L1 (rest L2)))))
                               
;(trace fusion)
;(fusion '(1 2 (3 8)) '(4 5 6))

(define (rev-dup L)
  (if (empty? L) '()
      (append (rev-dup (rest L)) (list (first L) (first L)))))
;(trace rev-dup)
;(rev-dup '(1 2 3))

(define (remove L E)
  (if (empty? L) '()
      (if (= (first L) E) (remove (rest L) E)
          (cons (first L) (remove (rest L) E)))))

;(remove '(1 2 3 4 4) 4)
;(remove '(1 2 3) 4)

(define (nlast L Indice)
  (if (<= (length L) Indice) L
      (nlast (rest L) Indice)))
;(trace nlast)
(nlast '(1 2 3 4 5 6) 8)
(nlast '(1 2 3 4 5 6) 3)
