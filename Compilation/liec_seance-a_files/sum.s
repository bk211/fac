.text
.globl main

main:
  li $v0, 4
  la $a0, num1q
  syscall

  li $v0, 5
  syscall
  move $t2, $v0

loop:
  beq $t2, $0, end_loop
  add $t1, $t1, $t2 
  addi $t2, $t2, -1

  b loop
end_loop:
  li $v0, 4
  la $a0, sum
  syscall
  
  move $a0, $t1
  li $v0, 1
  syscall  

  jr $ra

.data
num1q: .asciiz "Please enter the number N : "
sum:   .asciiz "The sum of these numbers is: "
nl:    .asciiz "\n"
