#include "unity.h"
#include "StringObject.h"

typedef struct FakeText{
	uint32 reference;
	char string[80];
}FakeText;

void setUp(void){}
void tearDown(void){}

void test_stringDump_explore(void){	
		FakeText fakeText = {
			.reference = 10,
			.string = "hello world"
		};
		String str = {
			.reference = 20,
			.text = (Text *)&fakeText,
			.start = 0,
			.length = 100
		};
		stringDump(&str);
}

void test_textDump_explore(void){	
		FakeText fakeText = {
			.reference = 3,
			.string = "dummy"
		};
	
		textDump((Text *)&fakeText);
}

void test_textNew_copy_character_to_string(void){
		Text *name1;
		name1 = textNew("Bye");
		textDump(name1);
		
		TEST_ASSERT_EQUAL(0x01,name1->reference);
}

void test_textAssign_assign_character(void){
		Text *name1 = t"HAHA";
		Text *name2;
		Text *name3;
		textDump(name1);
		name2 = textNew("Bye");
		textDump(name2);
		name3 = textAssign(name2);
		textDump(name2);
		textDump(name3);
		
		TEST_ASSERT_EQUAL(0x80000000,name1->reference);
		TEST_ASSERT_EQUAL(0x02,name3->reference);
		TEST_ASSERT_EQUAL(0x02,name2->reference);
}


void test_textDel_text_dynamic_delete_1(void){	
		Text *name2;
		Text *name3;
		name2 = textNew("Bye");
		textDump(name2);
		name3 = textAssign(name2);
		textDump(name2);
		textDump(name3);
		name3 = textDel(name3);
		textDump(name3);
		
		TEST_ASSERT_EQUAL(0x01,name2->reference);			
}

void test_textDel_text_dynamic_NULL(void){	
		Text *name2;
		Text *name3;
		name2 = textNew("AAA");
		textDump(name2);
		name3 = textAssign(name2);
		textDump(name2);
		textDump(name3);
		name3 = textDel(name3);
		textDump(name3);
		name2 = textDel(name2);
		textDump(name2);
		

		TEST_ASSERT_NULL(name2);			
}

void test_stringNew(void){
		Text *new = textNew("VVV");
		textDump(new);
		String *string = stringNew(new);
		stringDump(string);
		TEST_ASSERT_EQUAL(0x01,string->reference);
		TEST_ASSERT_EQUAL(0x02,new->reference);
}

void test_stringAssign(void){
		Text *new = textNew("VVV");
		textDump(new);
		String *string1 = stringNew(new);
		stringDump(string1);
		String *string2 = stringAssign(string1);
		stringDump(string2);
		
		TEST_ASSERT_EQUAL(0x02,string1->reference);
		TEST_ASSERT_EQUAL(0x02,string2->reference);
		TEST_ASSERT_EQUAL(0x02,new->reference);
}	

void test_stringDel_1(void){
		Text *new = textNew("VVV");
		textDump(new);
		String *string1 = stringNew(new);
		stringDump(string1);
		String *string2 = stringAssign(string1);
		stringDump(string2);
		string1 = stringDel(string1);
		stringDump(string1);
		
		TEST_ASSERT_EQUAL(0x01,string1->reference);
	
}

void test_stringDel_null(void){
		Text *new = textNew("VVV");
		textDump(new);
		String *string1 = stringNew(new);
		stringDump(string1);
		String *string2 = stringAssign(string1);
		stringDump(string2);
		string1 = stringDel(string1);
		stringDump(string1);
		string2 = stringDel(string2);
		stringDump(string2);
		
		TEST_ASSERT_NULL(string2);
}

void test_stringSkip(void){
		
		String *string1 = stringNew(textNew("VVV"));
		stringSkip(string1,2);
		stringDump(string1);
		TEST_ASSERT_EQUAL(0x02,string1->start);
		TEST_ASSERT_EQUAL(0x01,string1->length);

}

void test_stringTrimLeft(void){

		String *string1 = stringNew(textNew("   VVV"));
		stringTrimLeft(string1);
		stringDump(string1);
		TEST_ASSERT_EQUAL(0x03,string1->start);
		TEST_ASSERT_EQUAL(0x03,string1->length);
}

void test_stringTrimRight(void){

		String *string12 = stringNew(textNew("aaa           "));
		stringTrimRight(string12);
		stringDump(string12);
		TEST_ASSERT_EQUAL(0x00,string12->start);
		TEST_ASSERT_EQUAL(0x03,string12->length);
}

void test_stringTrim(void){

		String *string1 = stringNew(textNew("   VVV  "));
		stringTrim(string1);
		stringDump(string1);
		TEST_ASSERT_EQUAL(0x03,string1->start);
		TEST_ASSERT_EQUAL(0x03,string1->length);
}

void test_stringRemoveChar(void){
		char character;
		String *string1 = stringNew(textNew("a"));
		stringRemoveChar(string1);
		character = stringRemoveChar(string1);
		stringDump(string1);
		TEST_ASSERT_EQUAL(0,string1->length);
		TEST_ASSERT_EQUAL(-1,character);
}

void test_stringLength(void){
		char character;
		String *string1 = stringNew(textNew("aliaaa"));
		character = stringLength(string1);
		stringDump(string1);
		
		TEST_ASSERT_EQUAL(6,string1->length);
}

void test_stringRemoveWordNotContaining(void){

		Text *new = textNew("abcdefghi");
		String *string1 = stringNew(new);
		String *a = stringRemoveWordNotContaining(string1,"ei");
		stringDump(a);
		stringDump(string1);
		TEST_ASSERT_EQUAL(0,a->start);
		TEST_ASSERT_EQUAL(4,a->length);
		TEST_ASSERT_EQUAL(4,string1->start);
		TEST_ASSERT_EQUAL(9,string1->length);
}


void test_stringRemoveWordContaining(void){

		Text *new = textNew("eiejj");
		String *string1 = stringNew(new);
		String *a = stringRemoveWordContaining(string1,"ei");
		stringDump(a);
		stringDump(string1);
		
		TEST_ASSERT_EQUAL(0,a->start);
		TEST_ASSERT_EQUAL(3,a->length);
		TEST_ASSERT_EQUAL(3,string1->start);
		TEST_ASSERT_EQUAL(5,string1->length);
	
}

void test_stringlsEqual(void){
		int input;
		Text *name2;
		Text *name3;
		name2 = textNew("samsung");
		String *string1 = stringNew(name2);
		string1->start = string1->start+3;
		string1->length = string1->length-3;
		name3 = textNew("sung");
		String *string2 = stringNew(name3);
		
		input = stringlsEqual(string1,string2);
		
		TEST_ASSERT_EQUAL(1,input);
	
}

void test_stringlsEqualCaseInsensitive(void){
		int input;
		Text *name2;
		Text *name3;
		name2 = textNew("HAlo");
		String *string1 = stringNew(name2);
		name3 = textNew("halO");
		String *string2 = stringNew(name3);
		
		input = stringlsEqualCaseInsensitive(string1,string2);
		stringDump(string1);
		stringDump(string2);
		
		TEST_ASSERT_EQUAL(1,input);
	
}