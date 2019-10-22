	.data
descriptor:	.space 12
theBucket:	.space 80
printMenu:	.asciiz "\n1 - Insert element in the list\n2 - Update/Remove\n3 - Radix sort\n4 - Print list\n5 - Exit\nOption: "
askValue:	.asciiz "\nType a value: "
whatDo:	.asciiz "\nUpdate or remove? [0] Update / [1] Remove: "
newValue:	.asciiz "\nType a new value: "
askIndex:	.asciiz "\nType the index of element: "
msg_Inval:	.asciiz "\nInvalid option\n"
msg_empty:	.asciiz "\nEmpty list\n"
charEnter:	.asciiz "\n"
openSquareBrac:	.asciiz "Index ["
end_SquareBrac:	.asciiz "] = "
	.text

main:
	la $s0, descriptor
	sw $zero, 0($s0)	
	sw $zero, 4($s0)	
	sw $zero, 8($s0)	
	move $s1, $zero		

menuOp:
	li  $v0, 4
	la $a0, printMenu
	syscall

	li $v0, 5
	syscall

	beq $v0, 1, insert_element
	beq $v0, 2, search
	beq $v0, 3, order
	beq $v0, 4, show_list
	beq $v0, 5, exit

	j showInvalid

insert_element:
	li $v0, 4
	la $a0, askValue
	syscall

	li $v0, 5
	syscall
	move $t0, $v0 		

	li $v0, 9
	addi $a0, $zero, 12
	syscall

	lw $t1, 4($s0)		
	addi $t1, $t1, 1
	sw $t1, 4($s0)

	sw $t0, 4($v0)
	sw $zero, 8($v0)

	lw $s1, 8($s0)		
	bne $s1, $zero, insertEnd	
	sw $v0, 0($s0)		

insertEnd:
	sw $v0, 8($s0)		
	sw $s1, 0($v0)		
	beq $s1, $zero, return
	sw $v0, 8($s1)		
	b return

search:
	li $v0, 4
	la $a0, askIndex
	syscall
	li $v0, 5
	syscall
	lw $t1, 0($s0)			
	lw $t0, 4($s0)			
	addi $t2, $zero, -1		
	blt $v0, $t0, loop_search
	li $v0, 4
	la $a0, msg_Inval
	syscall

	b return

loop_search:
	move $t0, $t1
	lw $t1, 8($t1)
	addi $t2, $t2, 1
	blt $t2, $v0, loop_search

	li $v0, 4
	la $a0, whatDo
	syscall

	li $v0, 5
	syscall

	beq $v0, 1, remove_element
	bne $v0, $zero, showInvalid

	li $v0, 4
	la $a0, newValue
	syscall

	li $v0, 5
	syscall

	sw $v0, 4($t0)
	b return

remove_element:
	lw $t7, 4($s0)
	addi $t7, $t7, -1
	sw $t7, 4($s0)
	lw $t2, 0($t0)	
	lw $t3, 8($t0)	
	beq $t2, $zero, remove_first
	beq $t3, $zero, remove_last
	sw $t2, 0($t3)
	sw $t3, 8($t2)

	b return
remove_first:
	sw $t3, 0($s0)
	beq $t3, $zero, main
	sw $zero, 0($t3)

	b return

remove_last:
	sw $t2, 8($s0)
	beq $t2, $zero, main
	sw $zero, 8($t2)

	b return

show_list:
	lw $s1, 0($s0)		
	beq $s1, $zero, emptyList
	move $t0, $zero

loop:
	lw $t1, 4($s1)	

	li $v0, 4
	la $a0, charEnter
	syscall

	li $v0, 4
	la $a0, openSquareBrac
	syscall

	li $v0, 1
	move $a0, $t0
	syscall

	li $v0, 4
	la $a0, end_SquareBrac
	syscall

	li $v0, 1
	move $a0, $t1
	syscall

	lw $s1, 8($s1)
	addi $t0, $t0, 1
	bne $s1, $zero, loop

	li $v0, 4
	la $a0, charEnter
	syscall

	b return

return:
	b menuOp


emptyList:
	li $v0, 4
	la $a0, msg_empty
	syscall
	j menuOp

showInvalid:
	li $v0, 4
	la $a0, msg_Inval
	syscall
	j menuOp

order:
	lw $t0, 4($s0)
	beq $t0, $zero, emptyList

	li $t1, 4				
	mult $t0, $t1
	mflo $t0
	sub $sp, $sp, $t0

	move $s1, $sp			
	lw $a0, 0($s0)
	jal	searchBigger

	move $s4, $v0			
	li $t1, 1

radix:
	jal cleanBucket

	lw $t0, 0($s0)			
	la $s2, theBucket		
	addi $s2, $s2, 40	
	li $t2, 10				
	li $t4, 4

	bgt $t1, $s4, disaloc

fillBucket:
	jal accessBucket

	lw $t3, 0($v1)

	addi $t3, $t3, 1
	sw $t3, 0($v1)

	lw $t0, 8($t0)				

	bne $t0, $zero, fillBucket	

	la $t0, theBucket
	lw $t6, 0($t0)
	addi $t0, $t0, 4
	li $t5, 1

sum_buckets:
	lw $t7, 0($t0)
	add $t6, $t6, $t7
	sw $t6, 0($t0)
	addi $t0, $t0, 4
	addi $t5, $t5, 1
	blt $t5, 20, sum_buckets

	lw $t0, 8($s0)				

fill_aux:
	jal accessBucket

	lw $t3, 0($v1)

	addi $t3, $t3, -1
	sw $t3, 0($v1)

	mult $t3, $t4
	mflo $t3
	sub $t3, $s1, $t3			

	lw $t5, 4($t0)				
	sw $t5, 0($t3)				
	lw $t0, 0($t0)				
	bne $t0, $zero, fill_aux

	lw $t0, 0($s0)				
	lw $t5, 4($s0)				
	li $t2, 0					
	move $t3, $s1				

fill_list:
	lw $t4, 0($t3)				
	sw $t4, 4($t0)				
	lw $t0, 8($t0)				

	addi $t3, $t3, -4			
	addi $t2, $t2, 1			

	blt $t2, $t5, fill_list
	mult $t5, $t2
	mflo $t5

	li $t2, 10
	mult $t2, $t1
	mflo $t1

	b radix

accessBucket:
	lw $t3, 4($t0)
	div $t3, $t1
	mflo $t3

	div $t3, $t2
	mfhi $t3

	mult $t4, $t3
	mflo $t3

	add $v1, $s2, $t3 			
	jr $ra

searchBigger:
	li $t7, -1	
	lw $t0, 4($a0)	
	mult $t0, $t7
	mflo $t6
	bgt $t6, $t0, isBigger
		
loopMaior:
	lw $a0, 8($a0)
	beq $a0, $zero, endList	
	lw $t6, 4($a0)
	bgt $t6, $t0, isBigger
	mult $t6, $t7
	mflo $t6
	bgt $t6, $t0, isBigger
	b loopMaior
isBigger:
	move $t0, $t6
	b loopMaior
endList:
	move $v0, $t0
	jr $ra

cleanBucket:
	la $s6, theBucket
	move $s7, $zero
loopBucket:
	sw $zero, 0($s6)
	addi $s7, $s7, 1
	addi $s6, $s6, 4
	blt $s7, 20, loopBucket
	jr $ra

disaloc:
	lw $t7, 4($s0)
	li $t4, 4
	mult $t4, $t7
	mflo $t7
	add $sp, $sp, $t7

	b return

exit:
	li $v0, 10
	syscall
