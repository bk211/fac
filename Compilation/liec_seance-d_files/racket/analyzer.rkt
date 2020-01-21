#lang racket/base

(require racket/match
         "ast.rkt"
         "baselib.rkt"
         "helper.rkt")

(provide analyze)

(define (expr-pos e)
    (match e
        [(Pnil pos) pos]
        [(Pnum _ pos) pos]
        [(Pstr _ pos) pos]
        [(Pcall _ _ pos) pos]
        [(Pvar _ pos) pos]
        )
    )

(define (analyze-expr expr env)
  (match expr
    [(Pnil pos)
     (cons (Nil)
           (Pair 'num))]
    [(Pnum n pos)
     (cons (Num n)
           'num)]
    [(Pstr s pos)
     (cons (Str s)
           'str)]
    [(Pvar v pos)
        (unless (hash-has-key? env v)
            (err (format "unbound variable")))
        ]

    [(Pcall f as pos)
     (let ([ft (hash-ref env f
                         (lambda ()
                           (err (format "undefined function '~a'" f) pos)))])
       (unless (Fun? ft)
         (err (format "value '~a' is not a function" f) pos))
       (unless (= (length as) (length (Fun-args ft)))
         (err (format "function '~a' expects ~a arguments but was given ~a"
                      f (length (Fun-args ft) (length as))) pos))
       (let ([aas (map (lambda (a at)
                         (let ([aa (analyze-expr a env)])
                           (unless (equal? at (cdr aa))
                             (errt at (cdr aa) pos))
                           (car aa)))
                       as (Fun-args ft))])
         (cons (Call f aas)
               (Fun-ret ft))))]))


(define (analyze-instr instr env)
    (match instr
        [(Passign v e pos)
            (let ([ae (analyze-expr e env)])
                (cons (Assign v (car ae))
                    'void ))
            ]
        [(Pexpr e pos)
            (let ([ae (analyze-expr e env)])
                (cons (Expr (car ae))
                    env
                    )

            ]
        ))

(define (analyze-prog prog env)
    (match prog
        ['() (list)]
        [(cons i p)
            (let ([ai (analyze-instr i env)])
            (unless (equal? 'void (cdr ae))
                (errt 'void (cdr ae) (expr-pos e)))
            (cons (car ae) (analyze-prog p env)))]))

(define (analyze ast)
  (car (analyze-prog ast *baselib-types*)))
