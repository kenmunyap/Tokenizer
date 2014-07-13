#include "unity.h"
#include "FDA.h"
#include "CException.h"
#include "mock_Evaluate.h"
#include "CustomTypeAssert.h"
#include "StringObject.h"
#include "String.h"
#include "Text.h"
#include "ErrorCode.h"


void setUp(void){}
void tearDown(void){}

void test_operand1ExtractValue(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndThrow(string,3);
	
	Try{
		operand1ExtractValue(string);
	}Catch(error){
		TEST_ASSERT_EQUAL(error,ERR_EMPTY_VALUE);
		return;
	}
	TEST_FAIL_MESSAGE("No exception thrown.");
}


void test_operand1ExtractValue_it_is_value(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	
	extractValue_ExpectAndReturn(string,0x123);
	value = operand1ExtractValue(string);
			
			
	TEST_ASSERT_EQUAL(value,0x123);
}

void test_operand2ExtractDestination_is_empty_argument(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	


	extractDestination_ExpectAndThrow(string,4);
	Try{
		operand2ExtractDestination(string);
	}Catch(error){
		TEST_ASSERT_EQUAL(error,ERR_INVALID_ARGUMENT);
		return;
	}
	TEST_FAIL_MESSAGE("No exception thrown.");
	
}

void test_operand2ExtractDestination_is_not_empty_argument(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	

	extractDestination_ExpectAndThrow(string,6);
	value = operand2ExtractDestination(string);


	TEST_ASSERT_EQUAL(value,0x1);
	
}

void test_operand3ExtractACCESSBANKED_is_empty_argument(void){
	int value,error;

	Text *new = textNew("");
	String *string = stringNew(new);
	

	extractACCESSBANKED_ExpectAndThrow(string,4);
	Try{
		operand3ExtractACCESSBANKED(string,0);
	}Catch(error){
		TEST_ASSERT_EQUAL(error,ERR_INVALID_ARGUMENT);
		return;
	}
	TEST_FAIL_MESSAGE("No exception thrown.");
}


void test_operand3ExtractACCESSBANKED_is_not_empty_argument(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	

	extractACCESSBANKED_ExpectAndThrow(string,6);
	value = operand3ExtractACCESSBANKED(string,0x20);


	TEST_ASSERT_EQUAL(value,0x1);
}

void test_operand3ExtractACCESSBANKED_is_not_empty_argument1(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	

	extractACCESSBANKED_ExpectAndThrow(string,6);
	value = operand3ExtractACCESSBANKED(string,0x81);


	TEST_ASSERT_EQUAL(value,0x0);
}

void test_FDA1(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	extractValue_ExpectAndReturn(string,0x23);
	extractDestination_ExpectAndThrow(string,6);
	extractACCESSBANKED_ExpectAndThrow(string,6);


	value = FDA(string);
		
	TEST_ASSERT_EQUAL(value,0x25);
}

void test_FDA2(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	extractValue_ExpectAndReturn(string,0x123);
	extractDestination_ExpectAndThrow(string,6);
	extractACCESSBANKED_ExpectAndThrow(string,6);
	value = FDA(string);
		
	TEST_ASSERT_EQUAL(value,0x24);
}

void test_FDA3(void){
	int value,error;
	Text *new = textNew("");
	String *string = stringNew(new);
	extractValue_ExpectAndReturn(string,0x123);
	extractDestination_ExpectAndReturn(string,0);
	extractACCESSBANKED_ExpectAndReturn(string,0);
	value = FDA(string);
		
	TEST_ASSERT_EQUAL_HEX8(value,0x23);
}


