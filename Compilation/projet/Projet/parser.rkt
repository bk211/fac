#lang racket/base

(require parser-tools/yacc
         parser-tools/lex
         "lexer.rkt"
         "ast.rkt"
         "helper.rkt")

(provide parse)

(define ~parse
  (parser
   (src-pos)
   (tokens constants operators)
   (start prog)
   (end Leof)
   (grammar
    (prog
     [(Lnum) (Pnum $1 $1-start-pos)]))
   (error (lambda (tok-ok? tok-name tok-value start-pos end-pos)
            (err (format "~a:~a: Syntax error"
                         (position-line start-pos)
                         (position-col start-pos)))))))

(define (parse src)
  (~parse (lambda () (get-token src))))