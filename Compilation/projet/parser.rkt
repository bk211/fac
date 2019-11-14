#lang racket/base

(require parser-tools/yacc
         parser-tools/lex
         racket/port
         "lexer.rkt"
         "helper.rkt"
         "ast.rkt")

(provide parse)

(define ~parse
    (parser
        (src-pos)
        (tokens constants operators)
        (start prog)
        (end Leof)
        (grammar
            (prog
                [(expr) $1]
                [(expr Lplus expr) (Padd $1 $3 $1-start-pos)]
                (expr
                [(Lnum) (Pnum $1 $1-start-pos)]))
                )
        (error (lambda (tok-ok? tok-name tok-value start-pos end-pos)
                (err (format "~a:~a: syntax error"
                    (position-col start-pos) (position-line start-pos)))
                ))))

(define (parse src)
    (~parse (lambda () (get-token src))))
