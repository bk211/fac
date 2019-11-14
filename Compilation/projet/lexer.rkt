#lang racket/base

(require parser-tools/lex
         (prefix-in : parser-tools/lex-sre)
         "helper.rkt")

(provide constants get-token operators)

(define-tokens constants
    (Lnum) )

(define-empty-tokens operators
    (Leof Lplus))


(define get-token
    (lexer-src-pos
        [whitespace (return-without-pos (get-token input-port))]
        [(:+ numeric) (token-Lnum (string->number lexeme))]
        [(eof)  (token-Leof)]
        ["+" (token-Lplus)]
        (any-char (err (format "Unrecognized char '~a'" lexeme)))

    )
)
