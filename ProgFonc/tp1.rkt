#lang racket
(define (pgcd a b)
  (cond ((= a b) a)
      ((< a b) (pgcd b a))
      (else (pgcd (- a b)b))))

(define (pgcd-e a b)
  (cond ((< a b) (pgcd-e b a))
        ((= (remainder a b) 0) b)
        (else (pgcd-e (remainder a b) b))))
(define (f x)
  (if (= x 0) 3
      (+ 1 (* 2 (f (- x 1))))))