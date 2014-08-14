#include <stdio.h>
#include "N.h"
#include "Extract.h"
#include "StringObject.h"
#include "String.h"
#include "CustomTypeAssert.h"
#include "CException.h"
#include "ErrorCode.h"
#include "MaskTable.h"
#include "ExtractValue.h"


/*
*  N: return opcode to LSB 8bit or 12bit;		 
*/
int N(String *arguments , int numberOfbits){
	int value,value1;
	int operand1;
	int opcode;
	
	value = maskTable[numberOfbits];
	value1 = operand1ExtractValue(arguments);	
	operand1 = value & value1;
	
	return opcode = operand1;
}

/*  
*  
*  N8:
*		Input 8bit value
* 	    Return:
*			LSB 8bit to N
*
*/
int N8(String *arguments){
	return N(arguments,7);
}

/*  
*	N12:
*		Input 12bit value
*	Return:
*			LSB 12bit to N
*/
int N12(String *arguments){
	return N(arguments,11);
}