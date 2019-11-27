  .data
newline: .asciiz "\n"

  .text
  .globl main
_pair:
  li $a0, 8
  li $v0, 9
  syscall
  lw $t0, 4($sp)
  sw $t0, -4($v0)
  lw $t0, 0($sp)
  sw $t0, 0($v0)
  jr $ra
main:
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  li $v0, 42
  addi $sp, $sp, -4
  sw $v0, 0($sp)
  li $v0, 13
  addi $sp, $sp, -4
  sw $v0, 0($sp)
  li $v0, 0
  addi $sp, $sp, -4
  sw $v0, 0($sp)
  jal _pair
  addi $sp, $sp, 8
  addi $sp, $sp, -4
  sw $v0, 0($sp)
  jal _pair
  addi $sp, $sp, 8
  addi $sp, $sp, -4
  sw $v0, 0($sp)
  lw $t0, 0($sp)
  lw $v0, 0($t0)
  addi $sp, $sp, 4
  addi $sp, $sp, -4
  sw $v0, 0($sp)
  lw $t0, 0($sp)
  lw $v0, -4($t0)
  addi $sp, $sp, 4
  addi $sp, $sp, -4
  sw $v0, 0($sp)
  lw $a0, 0($sp)
  li $v0, 1
  syscall
  addi $sp, $sp, 4
  la $a0, newline
  li $v0, 4
  syscall
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  jr $ra
