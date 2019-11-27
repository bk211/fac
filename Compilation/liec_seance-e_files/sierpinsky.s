.text
.globl main

main:
    li $t0, 1  #x
    li $t7, 2147483647

    begin_w1:
        slt $t6, $t7, $t0
        beq $t6, $t0, end_func #si x < 2147483648, end_func


        move $t1, $t0  #n recoit x

        begin_w2:
            blez $t1, print_shift #n > 0
            and $t5, $t1, 1 # test si n est impair
            beq $t5, $0, pair

            li $v0, 4
            la $a0, hashtag
            syscall
            j exit_odd_test

            pair:
                li $v0, 4
                la $a0, space
                syscall

            exit_odd_test:
                sra $t1, $t1,1
                b begin_w2

        print_shift:
            li $v0, 4
            la $a0, nl
            syscall

            move $t4, $t0   # $t4 recoit temporairement x <<1
            sll $t4, $t4, 1
            xor $t0, $t0, $t4 # effectue l'XOR et stock dans x
            b begin_w1

    end_func:
        jr $ra

.data
hashtag:  .asciiz "#"
space:  .asciiz " "
nl:    .asciiz "\n"
