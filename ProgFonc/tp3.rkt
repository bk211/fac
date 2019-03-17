#lang racket
(require racket/trace)
(define (nfirst L n)
  (if (empty? L) '()
      (if(= n 0) '()
      (append (list(first L)) (nfirst (rest L) (- n 1)))
            ))
      )
;(nfirst (list 1 2 3) 5)
;(nfirst '() 1)
;(nfirst (list 1 2 3) 1)

(define (Aux-nbleaves L n)
  (if (empty? L) n 
      (if (list? (first L)) (+ (Aux-nbleaves (first L) 0) (Aux-nbleaves (rest L) n))
          (Aux-nbleaves (rest L) (+ n 1)))
      ))



;(Aux-nbleaves (list 1 2) 0)
;(Aux-nbleaves (list 1) 0)
;(Aux-nbleaves '((1 2) ((3 4) 5)) 0)
;(Aux-nbleaves '((1 2) 3) 0)
(define a (list (list 1 (list 2 3))))
;a
;(Aux-nbleaves a 0)


          

(define (nb-leaves T)
  (if (list? T)
          (if (= (length T) 1)
              (nb-leaves (first T))
              (+ (nb-leaves (first T))
                 (nb-leaves (rest T))))
      1))

          

(define abef list)

(define sag? list?)
(define (sag2? T) (> (length T) 0))

(define (sad? T) (= (length T) 2))
(define (sad2? T) (> (length T) 1))

(define (sag T) (first T))
(define (sad T) (first (rest T)))
(define (leaf? T) (not(list? T)))

(define (nb-leaves2 T)
  (if (sag? T)
      (if (sad? T)
          (+ (nb-leaves2 (sag T)) (nb-leaves2 (sad T)))
      (nb-leaves2 (sag T)))
      1))
;(nb-leaves a)
;(first (first a))
;(leaf? (first(first a)))

(define (nb-nodes T)
  (if (sag? T)
      (if (sad? T)
          (+ 1 (nb-nodes (sag T)) (nb-nodes (sad T)))
          (+ 1 (nb-nodes (sag T))))
      1))
;(trace nb-nodes)
;(nb-nodes a)
(define a2 (list(list 1 (list 2 3)) (list (list 4 5))) ) 
;a2
;(nb-nodes a2)

(define (h T n)
  (if (sag? T)
      (if (sad? T)
          (max (h (sag T) (+ n 1)) (h (sad T) (+ n 1)))
          (max (h (sag T) (+ n 1))))
      n))
;(h a 0)
(define a3 (list 'a (list 'b 1)))
;a3
;(h a2 0)
;(h a3 0)

(define a4 (list 'a (list 'b 1 (list 'c 2 3))))
;a4 
;(h a4 0)
(define a5 (list 'a (list 'b 1 (list 'c 2 3)) (list 'd 5)))
;(h a5 0)


(define (hauteur T)
  (if (sag? T)
      (if (sad? T)
          (+ 1 (max (hauteur (sag T))
                    (hauteur (sad T))))
          (+ 1 (hauteur (sag T)))
      )
  0))
;a
;(hauteur a)
;(hauteur a2)
;(hauteur a3)
;(hauteur a4)
;(hauteur a5)

(define (NBI T);nb noeud intermediaire
  (if (sag? T)
      (if (sad? T)
          (+ 1 (NBI (NBI (sag T))
                   (NBI (sad T))))
          (+ 1 (NBI (sag T)))
      )
  0))


