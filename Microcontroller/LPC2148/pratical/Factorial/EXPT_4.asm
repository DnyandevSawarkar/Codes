; Factorial
	AREA RESET,CODE,READONLY
START
	MOV R0,#0X04
	MOV R1,#0X01
	CMP R0,#0X01
	BEQ SKIP
	
LOOP
	MUL R1,R0,R1
	SUB R0,R0,#0X01
	CMP R0,#0X01
	BNE LOOP
	
STOP B STOP	

SKIP
	MOV R1,#0X01
	END