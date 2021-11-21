#include "libft.h"
#include "unity.h"
#include "ctype.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_when_ascii_then_1(void)
{
	TEST_ASSERT_EQUAL(isascii(0), ft_isascii(0));
	TEST_ASSERT_EQUAL(isascii(127), ft_isascii(127));
	TEST_ASSERT_EQUAL(isascii('a'), ft_isascii('a'));
	TEST_ASSERT_EQUAL(isascii('2'), ft_isascii('2'));
	TEST_ASSERT_EQUAL(isascii('A'), ft_isascii('A'));
}

void	test_when_ascii_then_0(void)
{
	TEST_ASSERT_EQUAL(isascii(-1), ft_isascii(-1));
	TEST_ASSERT_EQUAL(isascii(128), ft_isascii(128));
}
