	.orig x3000
MAIN
	JSR GETNUM
	JSR GETNUM ;Yes, there are TWO calls to GETNUM
	HALT
GETNUM	
	ST R1, GN_SR1
	ST R2, GN_SR2
	ST R3, GN_SR3
	ST R7, GN_SR7
FIND
	GETC
	LD R1, L0
	LD R2, L9
	ADD R0, R0, R1
	ADD R3, R0, R2
	BRZ GETNUM_END
	BRP FIND
	ADD R3, R0, #1
	BRNZ FIND
GETNUM_END
	;Restore R1 and R2
	LD R1, GN_SR1
	LD R2, GN_SR2
	LD R3, GN_SR3
	LD R7, GN_SR7
RET
; Create storage locations GN_SR1, GN_SR2, and GN_SR3
; Do this immediately after the RET for all subroutines
GN_SR1 	.fill 0
GN_SR2 	.fill 0
GN_SR7 	.fill 0
GN_SR3 	.fill 0
L0 	    .fill x-30
L9		.fill x-09

