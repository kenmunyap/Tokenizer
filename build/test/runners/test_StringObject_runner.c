/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
    CEXCEPTION_T e; \
    Try { \
      setUp(); \
      TestFunc(); \
    } Catch(e) { TEST_ASSERT_EQUAL_HEX32_MESSAGE(CEXCEPTION_NONE, e, "Unhandled Exception!"); } \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>
#include "CException.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_stringDump_explore(void);
extern void test_textDump_explore(void);
extern void test_textNew_copy_character_to_string(void);
extern void test_textAssign_assign_character(void);
extern void test_textDel_text_dynamic_delete_1(void);
extern void test_textDel_text_dynamic_NULL(void);
extern void test_stringNew(void);
extern void test_stringAssign(void);
extern void test_stringDel_1(void);
extern void test_stringDel_null(void);
extern void test_stringSkip(void);
extern void test_stringTrimLeft(void);
extern void test_stringTrimRight(void);
extern void test_stringTrim(void);
extern void test_stringRemoveChar(void);
extern void test_stringLength(void);
extern void test_stringRemoveWordNotContaining(void);
extern void test_stringRemoveWordContaining(void);
extern void test_stringlsEqual(void);
extern void test_stringlsEqualCaseInsensitive(void);


//=======Test Reset Option=====
void resetTest()
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test_StringObject.c";
  UnityBegin();
  RUN_TEST(test_stringDump_explore, 12);
  RUN_TEST(test_textDump_explore, 26);
  RUN_TEST(test_textNew_copy_character_to_string, 35);
  RUN_TEST(test_textAssign_assign_character, 43);
  RUN_TEST(test_textDel_text_dynamic_delete_1, 60);
  RUN_TEST(test_textDel_text_dynamic_NULL, 74);
  RUN_TEST(test_stringNew, 91);
  RUN_TEST(test_stringAssign, 100);
  RUN_TEST(test_stringDel_1, 113);
  RUN_TEST(test_stringDel_null, 127);
  RUN_TEST(test_stringSkip, 142);
  RUN_TEST(test_stringTrimLeft, 152);
  RUN_TEST(test_stringTrimRight, 161);
  RUN_TEST(test_stringTrim, 170);
  RUN_TEST(test_stringRemoveChar, 179);
  RUN_TEST(test_stringLength, 189);
  RUN_TEST(test_stringRemoveWordNotContaining, 198);
  RUN_TEST(test_stringRemoveWordContaining, 212);
  RUN_TEST(test_stringlsEqual, 227);
  RUN_TEST(test_stringlsEqualCaseInsensitive, 244);

  return (UnityEnd());
}
