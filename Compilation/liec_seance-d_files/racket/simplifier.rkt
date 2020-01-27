#lang racket/base

(require racket/match
         "ast.rkt")

(provide simplify)

(define uniq 0)
(define (collect-constant-strings ast)
    (match ast
      [(Nil)
       (cons (Nil)
             (list))]
      [(Num n)
       (cons (Num n)
             (list))]
      [(Str s)
       (set! uniq (add1 uniq))
       (let ([lbl (format "str_~a" uniq)])
         (cons (Data lbl)
               (list (cons lbl s))))]
      [(Call f a)
       (let ([as (map ccs a)])
         (cons (Call f (map car as))
               (apply append (map cdr as))))]))


(define (simplify-prog prog)
    (match prog
        ['() (cons (list) (list))]
        [(cons i p)
            (let ([si (collect-constant-strings i)]
                [sp (simplify-prog p)])
            (cons (cons (car si) (car sp))
            (append (cdr si) (cdr sp))))]))


(define (simplify ast)
  (collect-constant-strings ast))
