#lang racket/base

(require "parser.rkt"
         "analyze.rkt"
         "compile.rkt"
         "helper.rkt")

(define argv (current-command-line-arguments))
(cond
  [(= (vector-length argv) 1)
   (define src (open-input-file (vector-ref argv 0)))
   (port-count-lines! src)
   (define parsed (parse src))
   (define ast (analyze parsed))
   (define asm (compile ast))
   (mips-emit asm)]
  [else
   (err "Usage: racket liec.rkt <file>")])