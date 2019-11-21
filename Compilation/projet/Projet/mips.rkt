#lang racket/base

(provide (all-defined-out))

(struct ASM (data text) #:transparent)

(struct Asciiz (name str) #:transparent)

(struct Label (name) #:transparent)

(struct Addr (reg offset) #:transparent)
(struct Lbl (name) #:transparent)

(struct Li (dst imm) #:transparent)
(struct La (dst addr) #:transparent)
(struct Addi (dst reg imm) #:transparent)
(struct Sw (reg addr) #:transparent)
(struct Lw (reg addr) #:transparent)
(struct Move (dst reg) #:transparent)
(struct Syscall () #:transparent)
(struct Jr (reg) #:transparent)

(define print_int 1)
(define print_string 4)
