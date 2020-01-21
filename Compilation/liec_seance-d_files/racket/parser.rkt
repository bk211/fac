#lang racket/base

(require parser-tools/yacc
         parser-tools/lex
         "lexer.rkt"
         "ast.rkt"
         "helper.rkt")

(provide parse)

(define parse-syntax
  (parser
   (src-pos)
   (tokens constants operators)
   (start prog)
   (end Leof)
   (grammar
    (prog
        [() '()];programme vide
        [(instr)             (list $1)]
        [(instr Lsep prog)   (cons $1 $3)]
     )
     (instr
         [(Lident Lassign expr) (Passign $1 $3 $2-start-pos)]
         [(expr)    (Pexpr $1 $1-start-pos)]
         )
    (expr
     [(Lopar Lcpar)             (Pnil $1-start-pos)]
     [(Lnum)                    (Pnum $1 $1-start-pos)]
     [(Lstr)                    (Pstr $1 $1-start-pos)]
     [(Lident Lopar args Lcpar) (Pcall $1 $3 $1-start-pos)]
     [(expr Lplus expr)         (Pcall '%add (list $1 $3) $2-start-pos)])
    (args
     [()                 (list)]
     [(expr)             (list $1)]
     [(expr Lcomma args) (cons $1 $3)]))
   (precs
    (left Lplus))
   (error (lambda (tok-ok? tok-name tok-value start-pos end-pos)
            (err (format "syntax error near ~a~a"
                         (substring (symbol->string tok-name) 1)
                         (if tok-value
                             (format "(~a)" tok-value)
                             ""))
                 start-pos)))))

(define (parse src)
  (port-count-lines! src)
;    (displayln (get-token src))
;    (displayln (get-token src))
;    (displayln (get-token src))
;    (displayln (get-token src))
  (parse-syntax (lambda () (get-token src)))
)
