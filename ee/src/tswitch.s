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

	swc1 $f20, 88($a0)
	lwc1 $f20, 88($a1)

	swc1 $f21, 92($a0)
	lwc1 $f21, 92($a1)

	swc1 $f22, 96($a0)
	lwc1 $f22, 96($a1)

	swc1 $f23, 100($a0)
	lwc1 $f23, 100($a1)

	swc1 $f24, 104($a0)
	lwc1 $f24, 104($a1)

	swc1 $f25, 108($a0)
	lwc1 $f25, 108($a1)

	swc1 $f26, 112($a0)
	lwc1 $f26, 112($a1)

	swc1 $f27, 116($a0)
	lwc1 $f27, 116($a1)

	swc1 $f28, 120($a0)
	lwc1 $f28, 120($a1)

	swc1 $f29, 124($a0)
	lwc1 $f29, 124($a1)

	swc1 $f30, 128($a0)
	lwc1 $f30, 128($a1)


	jr $ra
