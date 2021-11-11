#include <stdio.h>

#include "unity.h"

#include "buffer.h"


void setUp (void)
{
	buffer_Init ();
}

void tearDown (void)
{

}

void test_buffer_index (void)
{
	int i;

	buffer_len = 0;
	for (i = 0; i < 256; i ++)
	{
		buffer_push (i);

		TEST_ASSERT_EQUAL_INT(buffer_len, (i+1) & 0xFF);
	}
}

void test_buffer_content (void)
{
	int i;
	uint8_t arr [256];

	buffer_len = 0;
	for (i = 0; i < 256; i ++)
	{
		arr [i] = 255-i;
		buffer_push (255-i);
	}

	TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, arr, 256);
}

void test_buffer_send (void)
{
	int ret, i;

	buffer_len = 0;
	for (i = 0; i < 256; i ++)
	{
		ret = buffer_push (i);

		if 		(i == 127)
			TEST_ASSERT_EQUAL_INT(ret, 0);
		else if (i == 255)
			TEST_ASSERT_EQUAL_INT(ret, 128);
		else
			TEST_ASSERT_EQUAL_INT(ret, -1);
	}
}


void run_test (UnityTestFunction test)
{
	if (TEST_PROTECT())
	{
		test ();
	}
}


int main ()
{
	UnityBegin ("main");
	RUN_TEST(test_buffer_index, 	__LINE__);
	RUN_TEST(test_buffer_content, 	__LINE__);
	RUN_TEST(test_buffer_send, 		__LINE__);
	UnityEnd ();


	return 0;
}
