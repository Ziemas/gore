.text

.globl gore_task_switch
gore_task_switch:
	sd $s0, 0($a0)
	ld $s0, 0($a1)
	sd $s1, 8($a0)
	ld $s1, 8($a1)
	sd $s2, 16($a0)
	ld $s2, 16($a1)
	sd $s3, 24($a0)
	ld $s3, 24($a1)
	sd $s4, 32($a0)
	ld $s4, 32($a1)
	sd $s5, 40($a0)
	ld $s5, 40($a1)
	sd $s6, 48($a0)
	ld $s6, 48($a1)
	sd $s7, 56($a0)
	ld $s7, 56($a1)
	sd $s8, 64($a0)
	ld $s8, 64($a1)
	sd $ra, 72($a0)
	ld $ra, 72($a1)
	sd $sp, 80($a0)
	ld $sp, 80($a1)

	jr $ra
