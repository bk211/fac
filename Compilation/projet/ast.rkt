#lang racket/base

(provide (all-defined-out))

(struct Pnum (n pos) #:transparent)
(struct Padd (a b pos) #:transparent)

(struct Num (n) #:transparent)
(struct Add (a b) #:transparent)
