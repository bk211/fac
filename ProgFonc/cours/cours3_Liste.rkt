#lang racket
(list "A" "B" 1)
(define ab (list 1 "m" 3))
(first ab)
ab
(define L empty)
(define VL '())
(cons 1 L) ;fusion de liste 1 et L

(list? L) ; bool ou predicat qui return la bool si type(L) = list

(list* 1 2 (list 1 3))
(list 1 2 (list 1 3))
(append (list "C" "D") (list "A" "B"))