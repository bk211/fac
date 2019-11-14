#lang racket/base

(require racket/match
        "ast.rkt"
        "helper.rkt")

(provide analyse)

(define (analyse-prog prog)
    (match prog
        [(Pnum n pos) (Num n)] ;;renvoie un Num
        [(Padd a b pos)
        (let ([aa (analyse-prog a)] [bb (analyse-prog a)]))
        (Add aa bb)]
        ))

(define (analyse ast)
    (analyse-prog ast))
