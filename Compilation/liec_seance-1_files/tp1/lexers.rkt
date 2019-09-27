#lang racket/base

(require parser-tools/lex
         (prefix-in : parser-tools/lex-sre))

(require racket/port)

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

(define str1 (open-input-string "Est-ce que ça marche ?"))
;;(first-lexer str1)


(define second-lexer
    (lexer
        (whitespace      (second-lexer input-port))
        ((eof)           (token-Fini))
        ("\n"          (token-Newline))
        (any-char        lexeme)
    )
)

(define (second-lex in)
    (let loop ((t (second-lexer in)))
    (unless (eq? t 'Fini)
        (write t)
        (newline)
        (loop (second-lexer in))
    )
))

(define str2 (open-input-string "Est-ce que ça remarche ?"))
;;(second-lex str2)

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
(second-lex file)
