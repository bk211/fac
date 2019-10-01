#lang racket/base

(require parser-tools/lex
         (prefix-in : parser-tools/lex-sre))

(require racket/port)
(require racket/trace)

(define-empty-tokens operators
    (Fini
    Opar Cpar Plus Moins
    Fois Divise Eq))

(define-tokens numbers (NUMBER))


(define tokenize
    (lexer
        (whitespace     (tokenize input-port))
        ((eof)          (token-Fini))
        ((:+ numeric)         (string->number lexeme))
        ((:+ alphabetic)        lexeme)
        ("("            (token-Opar))
        (")"            (token-Cpar))
        ("+"            (token-Plus))
        ("-"            (token-Moins))
        ("*"            (token-Fois))
        ("/"            (token-Divise))
        ("="            (token-Eq))
        (any-char       (error (format "Unrecognized char '~a' at offset ~a."
                                        lexeme (position-offset start-pos))))
    )

)