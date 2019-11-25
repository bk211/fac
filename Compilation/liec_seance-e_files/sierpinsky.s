.text
.globl main

main:
    li $t0, 1

    start:
        beq $t1, 1, end_loop
        li $t3,3

        b start

    end_loop:
        jr $ra

.data
num1q: .asciiz "Please enter the number N : "
sum:   .asciiz "The sum of these numbers is: "
nl:    .asciiz "\n"
