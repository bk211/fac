#lang racket/base

(require "parser.rkt"
        "helper.rkt"
        "analyse.rkt"
        "compile.rkt")

(define argv (current-command-line-arguments))
(cond
    [(= (vector-length argv) 1)
    (define src (open-input-file (vector-ref argv 0)))
    (port-count-lines! src)
    ;;(displayln (parse src))
    (define parsed (parse src))
    (define ast (analyse parsed))
    (define asm (compile ast))
    (mips-emit asm)]
    [else
        (err "Usage: racket liec.rkt <file>")]
)
