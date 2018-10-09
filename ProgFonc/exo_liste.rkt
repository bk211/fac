#lang racket
(define (Lto2L L) (if (empty? L) '()
                      (cons (first L) (cons (first L) (Lto2L (rest L))))
))
(Lto2L (list 1 2 3))

(define (Lto2Lbis L) (if (empty? L) '()
                      (append (list (first L)) (append (list (first L)) (Lto2Lbis (rest L))))
))
(Lto2Lbis (list empty))

(define (Lto3L L) (if (empty? L) '()
                     (cons (first L) (cons (first L) (cons (first L) (Lto3L (rest L)))))))
(Lto3L (list 1 2 3 4))

(define (Lto3Lbis L) (if (empty? L) '()
                     (append (list (first L) (first L) (first L)) (Lto3Lbis (rest L)))))
(Lto3Lbis (list 1 2 3 4))

(define (Lto3Lter L) (if (empty? L) '()
                     (list* (first L) (first L) (first L) (Lto3Lter (rest L)))))
(Lto3Lter (list 1 2 3 4))
