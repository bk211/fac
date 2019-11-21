#lang racket/base

(require racket/match
         "ast.rkt"
         "mips.rkt"
         "helper.rkt")

(provide compile mips-emit)

(define (compile-prog prog)
  (match prog
    [(Num n) (list (Li 'v0 n))]))

(define (compile ast)
  (ASM
   (list (Asciiz 'newline "\\n"))
   (append (list (Label 'main)
                 (Addi 'sp 'sp -4)
                 (Sw 'ra (Addr 'sp 0)))
           (compile-prog ast)
           (list (Move 'a0 'v0)
                 (Li 'v0 print_int)
                 (Syscall)
                 (La 'a0 (Lbl 'newline))
                 (Li 'v0 print_string)
                 (Syscall)
                 (Lw 'ra (Addr 'sp 0))
                 (Addi 'sp 'sp 4)
                 (Jr 'ra)))))

(define (mips-emit asm)
  (printf "  .data\n")
  (emit-data (ASM-data asm))
  (printf "  .text\n  .globl main\n")
  (emit-text (ASM-text asm)))

(define (print-dinstr instr)
  (match instr
    [(Asciiz n s) (printf "~a: .asciiz \"~a\"\n" n s)]))

(define (emit-data data)
  (for-each print-dinstr data)
  (printf "\n"))

(define (fmt-addr addr)
  (match addr
    [(Lbl n) (format "~a" n)]
    [(Addr r o) (format "~a($~a)" o r)]))

(define (print-instr instr)
  (match instr
    [(Label l)    (printf "~a:\n" l)]
    [(Li d i)     (printf "  li $~a, ~a\n" d i)]
    [(La d a)     (printf "  la $~a, ~a\n" d (fmt-addr a))]
    [(Addi d r i) (printf "  addi $~a, $~a, ~a\n" d r i)]
    [(Sw r a)     (printf "  sw $~a, ~a\n" r (fmt-addr a))]
    [(Lw r a)     (printf "  lw $~a, ~a\n" r (fmt-addr a))]
    [(Move d r)   (printf "  move $~a, $~a\n" d r)]
    [(Syscall)    (printf "  syscall\n")]
    [(Jr r)       (printf "  jr $~a\n" r)]))

(define (emit-text text)
  (for-each print-instr text))