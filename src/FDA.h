#ifndef _FDA_H_
#define _FDA_H_

#include "Evaluate.h"

int FDA(String *arguments);
int operand1ExtractValue(String *arguments);
int operand2ExtractDestination(String *arguments);
int operand3ExtractACCESSBANKED(String *arguments,int fileReg);
#endif //_FDA_H_