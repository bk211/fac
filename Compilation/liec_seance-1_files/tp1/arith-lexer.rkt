#lang racket/base

(require parser-tools/lex
         (prefix-in : parser-tools/lex-sre))

(require racket/port)
(require racket/trace)


(define-empty-tokens operators
    (Fini
    Opar Cpar Plus Moins
    Fois Divise Eq))

(define first-lexer
    (lexer
        (whitespace      (first-lexer input-port))
        ((eof)           (token-Fini))
        (any-char        (begin (printf lexeme)
                            (first-lexer input-port)))
    )
)


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
;;(lex file)

(define-tokens Identifiers
    (Number))

(port-count-lines! file)
(define tokenize2
    (lexer-src-pos
        (whitespace     (return-without-pos (tokenize2 input-port)))
        ("\n"     (return-without-pos (tokenize2 input-port)))
        ((eof)          (token-Fini))
        ((:+ numeric)         (string->number lexeme))
        ;;((:+ numeric)         (token-Number lexeme))
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



(define (print-token-pos t)
    (printf "~a ~ at:\n\tLine: ~a   Col: ~a to Col: ~a"
        (position-token-token t)
        (position-line (position-token-start-pos t))
        (position-col (position-token-start-pos t))
        (position-col (position-token-end-pos t))
    )
)

(define (lex2 in)
    (let loop
        ((t (tokenize2 in)))
            (unless (eq? 'Fini (position-token-token t))
            (print-token-pos t)
            (newline)
            (loop (tokenize2 in)))
    )
)

(lex2 file)

#|
(tokenize2 file)
(tokenize2 file)
(tokenize2 file)
(tokenize2 file)
(tokenize2 file)
|#
