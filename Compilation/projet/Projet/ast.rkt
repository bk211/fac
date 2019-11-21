#lang racket/base

(provide (all-defined-out))

(struct Pnum (n pos) #:transparent)

(struct Num (n) #:transparent)