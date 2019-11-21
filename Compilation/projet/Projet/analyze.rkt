#lang racket/base

(require racket/match
         "ast.rkt"
         "helper.rkt")

(provide analyze)

(define (analyze-prog prog)
  (match prog
    [(Pnum n pos) (Num n)]))

(define (analyze ast)
  (analyze-prog ast))