#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_when_less_than_10_then_1(void)
{
	TEST_ASSERT_EQUAL(1, ft_numlen(4));
}
void	test_when_2_digits_then_2(void)
{
	TEST_ASSERT_EQUAL(2, ft_numlen(56));
}
void	test_when_3_digits_then_2(void)
{
	TEST_ASSERT_EQUAL(3, ft_numlen(568));
}
