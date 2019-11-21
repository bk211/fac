  .data
newline: .asciiz "\n"

  .text
  .globl main
main:
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  li $v0, 12
  move $a0, $v0
  li $v0, 1
  syscall
  la $a0, newline
  li $v0, 4
  syscall
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  jr $ra
