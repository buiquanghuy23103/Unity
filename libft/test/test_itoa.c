#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	TEST_ASSERT_EQUAL_ITOA(int num, char *expected)
{
	char	*actual;

	actual = ft_itoa(num);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
}

void	test_when_negative_number(void)
{
	TEST_ASSERT_EQUAL_ITOA(-4235, "-4235");
}
void	test_when_zero(void)
{
	TEST_ASSERT_EQUAL_ITOA(0, "0");
}
void	test_when_positive(void)
{
	TEST_ASSERT_EQUAL_ITOA(4235, "4235");
}
void	test_when_min_int(void)
{
	TEST_ASSERT_EQUAL_ITOA(-2147483648,"-2147483648");
}
void	test_when_max_int(void)
{
	TEST_ASSERT_EQUAL_ITOA(2147483647, "2147483647");
}
