#lang racket
(define bintree list)
(define (leaf e) e)
(define (leaf? e) (not (list? e)))
(define (root T) (first T))
(define (L-subtree T) (first(rest T)))
(define (R-subtree T) (first(rest (rest T) )))
(define (has-L-subtree? T) (> (length T) 1))
(define (has-R-subtree? T) (> (length T) 2))
(require racket/trace)

(define T1 (bintree 17 (bintree 7 1 11) (bintree 111 71 171)))
(define T2 (bintree 71 (bintree 11 (bintree 7 1) 17) (bintree 111 171)))
T1
T2

(define (nbn T)
  (if (leaf? T) 1
      (if (has-R-subtree? T) (+ 1 (nbn (L-subtree T)) (nbn (R-subtree T)))
      (+ 1(nbn (L-subtree T)))
      )))
;(nbn T1)
;(nbn T2)
;(nbn (bintree 1 (bintree 2 3)))

(define (nbf T)
  (if (leaf? T) 1
      (if (has-R-subtree? T) (+ (nbf (L-subtree T)) (nbf (R-subtree T)))
      (nbf (L-subtree T))
      )))
;(trace nbf)
;(nbf T1)
;(nbf T2)

(define (nbni T)
  (define (nbni+1 T)
    (if (leaf? T) 0
      (if (has-R-subtree? T) (+ 1 (nbni+1 (L-subtree T)) (nbni+1 (R-subtree T)))
      (+ 1 (nbni+1 (L-subtree T)))
      )))
  (- (nbni+1 T) 1))
;(trace nbni)
;(nbni T1)
;(nbni T2)

(define (depth T)
  (if (leaf? T) 0
  (if (has-R-subtree? T) (+ 1 (max (depth (L-subtree T)) (depth (R-subtree T))))
      (+ 1 (depth (L-subtree T))))))

(depth T1)
(depth T2)
;(define (add-leaf T e)
 ; (if (not(has-R-subtree? T)) (append T (list e))
  ;    (if(= (power 2 (+ (depth (L-subtree T)) 1)) (nbn (L-subtree T)))
   ;   ))
(define (add-leaf T e)
  (if (not(has-R-subtree? T)) (bintree (root T) (L-subtree T) e)
      
  
  (if (> (nbn (R-subtree T)) (nbn (L-subtree T)))
      (bintree (root T) (add-leaf (L-subtree T) e) (R-subtree T))
      (bintree (root T) (L-subtree T) (add-leaf (R-subtree T) e)))

(define T3 (bintree 1 (bintree 2 3 )))
T3
(set! T3 (add-leaf T3 50))
T3
(set! T3 (add-leaf T3 50))
T3
