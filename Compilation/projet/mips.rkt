#lang racket/base

(provide (all-defined-out))

(struct Label (name) #:transparent)

(struct ASM (data text) #:transparent)
(struct Lbl (name) #:transparent)

(struct Asciiz (name str))

(struct Addr (reg offset) #:transparent)

(struct Li (dst imm) #:transparent)
(struct La (dst imm) #:transparent)
(struct Addi (dst reg imm) #:transparent)
(struct Madd (dst reg1 reg2) #:transparent)
(struct Sw (reg addr) #:transparent)
(struct Lw (reg addr) #:transparent)
(struct Move (dst reg) #:transparent)
(struct Syscall () #:transparent)
(struct Jr (reg) #:transparent)


(define print_int 1)
(define print_string 4)
