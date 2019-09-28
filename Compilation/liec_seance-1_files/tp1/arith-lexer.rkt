#lang racket/base

(require parser-tools/lex
         (prefix-in : parser-tools/lex-sre))

(require racket/port)
(require racket/trace)

;;(provide tokenize)

(define-empty-tokens operators
    (Fini
    Opar Cpar Plus Moins
    Fois Divise Eq Space))

(define first-lexer
    (lexer
        (whitespace      (first-lexer input-port))
        ((eof)           (token-Fini))
        (any-char        (begin (printf lexeme)
                            (first-lexer input-port)))
    )
)

(define str1 (open-input-string "Est-ce que ça marche ?"))
;;(first-lexer str1)

(define tokenize
    (lexer
        (whitespace     (tokenize input-port))
        ((eof)          (token-Fini))
        ((:+ alphabetic)        lexeme)
        ((:+ numeric)        lexeme)
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


(define arth1 (open-input-string "123()*-13=+ a 12 "))

(define (lex in)
    (let loop
        ((t (tokenize in)))
            (unless (eq? t 'Fini)
            (write t)
            (newline)
            (loop (tokenize in)))
    )
)

;;(trace lex)
;;(lex arth1)

(define argv (current-command-line-arguments))
(define filename "")

(cond
    ((= (vector-length argv) 1)
        (set! filename (vector-ref argv 0))
        )
    (else
        (eprintf "Usage: racket lexer.rkt [filename]\n")
        (exit 1)
    )
)

(define file (open-input-file filename))
(lex file)
