#lang racket/base

(require parser-tools/lex
         (prefix-in : parser-tools/lex-sre))

(require racket/port)
(require racket/trace)


(define-empty-tokens operators
    (Fini
    Po Pf Plus Moins
    Fois Divise Newline))

(define first-lexer
    (lexer
        (whitespace      (first-lexer input-port))
        ((eof)           (token-Fini))
        (any-char        (begin (printf lexeme)
                            (first-lexer input-port)))
    )
)
