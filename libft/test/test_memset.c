#include "libft.h"
#include "unity.h"
#include "ctype.h"
#include "string.h"
#include "stdlib.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_when_change_three_char(void)
{
	char	input_expected[40];
	char	input_actual[40];
	char	*expected;
	char	*actual;

	strcpy(input_expected, "Hello world!\n");
	strcpy(input_actual, "Hello world!\n");
	expected = (char*) memset(input_expected, 'z', 3);
	actual = (char*) ft_memset(input_actual, 'z', 3);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void	test_when_size_zero(void)
{
	char	input_expected[40];
	char	input_actual[40];
	char	*expected;
	char	*actual;

	strcpy(input_expected, "Hello world!\n");
	strcpy(input_actual, "Hello world!\n");
	expected = (char*) memset(input_expected, 'z', (0));
	actual = (char*) ft_memset(input_actual, 'z', (0));
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}
