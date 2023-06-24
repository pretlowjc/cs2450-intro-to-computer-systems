		.orig x3000
		JSR GETH4
		JSR GETH4
		HALT

GETHD	
		ST R7, SR7
		ST R5, SR5
		ST R4, SR4
		ST R3, SR3
GETTOP	GETC
		NOT R3, R0 
		ADD R3, R3, #1
		LD R5, ASCII0
		ADD R4, R3, R5
		BRp TEST2 
		NOT R3, R0
		ADD R3, R3, #1
		LD R5, ASCII9
		ADD R4, R3, R5
		BRn TEST2 
		OUT 
        LD R5, CONVNUM
        ADD R0, R0, R5 
        BRnzp GETEND
TEST2	
		NOT R3, R0
		ADD R3, R3, #1
		LD R5, ASCIIA
		ADD R4, R3, R5
		BRp TEST3
		NOT R3, R0
		ADD R3, R3, #1
		LD R5, ASCIIF
		ADD R4, R3, R5
		BRn TEST3 
		OUT 
        LD R5, CONVUP
        ADD R0, R0, R5
        BRnzp GETEND
TEST3	
		NOT R3, R0 
		ADD R3, R3, #1
		LD R5, ASCIIa
		ADD R4, R3, R5
		BRp TEST4 
		NOT R3, R0
		ADD R3, R3, #1
		LD R5, ASCIIF
		ADD R4, R3, R5
		BRn TEST4 
		OUT
        LD R5, CONVLOW
        ADD R0, R0, R5 
        BRnzp GETEND
TEST4	
		BRnzp GETTOP
GETEND  
		LD R5, SR5
		LD R4, SR4
		LD R3, SR3
		LD R7, SR7
		RET
		
MULT    ST R3, SR3
        AND R0, R0, #0
        ADD R1, R1, #1
        ADD R1, R1, #-1
        BRZ FINAL
        ADD R2, R2, #1
        ADD R2, R2, #-1
        BRZ FINAL
        AND R0, R0, #0
        NOT R3, R1
        ADD R3, R3, #1
        ADD R3, R3, R2
        BRN MULT2
        AND R3, R3, #0
        ADD R3, R1, #0
		
MULT1   ADD R0, R0, R2
        ADD R3, R3, #-1
        BRP MULT1
        BRNZP FINAL
		
MULT2   AND R3, R3, #0
        ADD R3, R2, #0
		
MULT3   ADD R0, R0, R1
        ADD R3, R3, #-1
        BRP MULT3
		
FINAL   LD R3, SR3
        RET
		
GETH4	ST R7, SR7_2
		ST R1, SR1
		ST R2, SR2
		ST R6, SR6
		
		AND R6, R6, #0
		
		JSR GETHD
		ST R0, SR0
		LD R1, SR0
		LD R2, HEX3
		JSR MULT
		ADD R6, R6, R0

		JSR GETHD
		ST R0, SR0
		LD R1, SR0
		LD R2, HEX2
		JSR MULT
		ADD R6, R6, R0
		
		JSR GETHD
		ST R0, SR0
		LD R1, SR0
		LD R2, HEX1
		JSR MULT
		ADD R6, R6, R0
		
		JSR GETHD
		ADD R6, R6, R0

		LD R0, ASCIINL
		OUT

		ST R6, SUM
		LD R0, SUM
		
		LD R7, SR7_2
		LD R1, SR1
		LD R2, SR2
		LD R6, SR6
		RET
		
SR0		.fill	#0
SR1		.fill	#0
SR2		.fill	#0
SR3		.fill	#0 
SR4		.fill	#0 
SR5		.fill	#0 
SR6 	.fill 	#0
SR7 	.fill	#0 
SR7_2	.fill 	#0
ASCII0  .fill	#48 
ASCII9  .fill	#57 
ASCIIA	.fill	#65 
ASCIIF	.fill	#70 
ASCIIa	.fill	#96 
CONVNUM .fill   #-48 
CONVUP  .fill   #-55 
CONVLOW .fill   #-87 
ASCIINL .fill	#10
SUM 	.fill 	#0
HEX1	.fill 	#16
HEX2	.fill	#256
HEX3	.fill	#4096
.end