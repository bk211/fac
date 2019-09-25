#lang racket/base

(require parser-tools/lex
         (prefix-in : parser-tools/lex-sre))

(provide first-lexer)

(define-empty-tokens operators
    (Fini
    Po Pf Plus Moins
    Fois Divise))

(define first-lexer
    (lexer
        (whitespace      (first-lexer input-port))
        ((eof)           (token-Fini))
        (any-char        (begin (printf lexeme)
                            (first-lexer input-port)))
    )
)

(define S (open-input-string "He lo o "))
(first-lexer S)
;;(call-with-input-string S first-lexer)

(define second-lexer
    (lexer
        (whitespace      (first-lexer input-port))
        ((eof)           (token-Fini))
        (any-char        lexeme
        )
    )
)

(define (second-lex in)
    (let loop ((t (first-lexer in)))
    (unless (eq? t 'Fini)
        (write t)
        (newline)
        (loop (first-lexer in))
    )
))

;;(second-lex S)
