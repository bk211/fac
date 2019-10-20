#lang racket/base

(require (only-in parser-tools/lex position-line position-col)
         racket/match
         racket/string
         "ast.rkt"
         "stdlib.rkt"
         racket/trace)

(provide analyze)

;; fonctions d'aide à la gestion des erreurs

(define (fail! msg)
  (eprintf "Fatal error: ~a.\n" msg)
  (exit 1))

(define (err msg pos)
  (eprintf "Error on line ~a col ~a: ~a.\n"
           (position-line pos)
           (position-col pos)
           msg)
  (exit 1))

(define (type->string t)
  (match t
    ['bool "boolean"]
    ['num  "number"]
    [(Fun r a)
     (string-append (if (> (length a) 1) "(" "")
                    (string-join (map type->string a) ", ")
                    (if (> (length a) 1) ")" "")
                    " -> " (type->string r))]))

(define (expr-pos expr)
  (match expr
    [(Pbool _ pos)     pos]
    [(Pnum _ pos)      pos]
    [(Pvar _ pos)      pos]
    [(Pcall _ _ pos)   pos]
    [(Pcond _ _ _ pos) pos]
    [else (fail! "not an expression")]))

(define (errt expected given pos)
  (err (format "expected ~a but given ~a"
               (type->string expected)
               (type->string given))
       pos))

;; analyse sémantique

(define (analyze parsed)
    (write ">>")
    (write parsed)
    (write "<<")
    (newline)
  (analyze-prog parsed (make-immutable-hash)))

(define (analyze-prog prog env)
  (match prog
    [(list)                 null]
    [(Passign a b c)         (write "jj")]
    [(cons i p)     (let ([ai (analyze-instr i env)]) (cons ai (analyze-prog p env)))]
))
;;(trace analyze-prog)

(define (analyze-instr instr env)
  (match instr
    [(Passign v e pos)
     (let ([ae (analyze-expr e env)])
       (Assign v ae))
       ]
    [else (fail! "not an instruction")])

    )

;;(trace analyze-instr)

(define (analyze-expr expr env)
  (match expr
    [(Pbool b pos)
     (Bool b)]
    [(Pnum n pos)
     (Num n)]
    [(Pvar v pos)
        (if (hash-has-key?) env v
        (Var v)]
        (err (format "unbound variable "))
        )
    [(Pcall f as pos)
     (let ([aas (map analyze-expr as)])
       (Call f aas))]
    [(Pcond t y n pos)
     (let ([at (analyze-expr t env)]
           [ay (analyze-expr y env)]
           [an (analyze-expr n env)])
       (Cond at ay an))]
    [else (fail! "not an expression")]))

;;(trace analyze-expr)
