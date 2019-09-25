#lang racket/base

(require racket/port
         "lexers.rkt")

(define (lex in)
  (let loop ((t (first-lexer in)))
    (unless (eq? t 'Fini)
      (write t)
      (newline)
      (loop (first-lexer in)))
    )
)

(define argv (current-command-line-arguments))
(cond
  ((= (vector-length argv) 1)
   (call-with-input-string (vector-ref argv 0) lex))
  (else
   (eprintf "Usage: racket lexer.rkt \"string\"\n")
   (exit 1)))
