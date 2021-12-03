#include "libft.h"
#include "unity.h"
#include "ctype.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_when_digit_then_1(void)
{
	TEST_ASSERT_EQUAL(isdigit('0'), ft_isdigit('0'));
	TEST_ASSERT_EQUAL(isdigit('1'), ft_isdigit('1'));
	TEST_ASSERT_EQUAL(isdigit('2'), ft_isdigit('2'));
	TEST_ASSERT_EQUAL(isdigit('3'), ft_isdigit('3'));
	TEST_ASSERT_EQUAL(isdigit('4'), ft_isdigit('4'));
	TEST_ASSERT_EQUAL(isdigit('5'), ft_isdigit('5'));
	TEST_ASSERT_EQUAL(isdigit('6'), ft_isdigit('6'));
	TEST_ASSERT_EQUAL(isdigit('7'), ft_isdigit('7'));
	TEST_ASSERT_EQUAL(isdigit('8'), ft_isdigit('8'));
	TEST_ASSERT_EQUAL(isdigit('9'), ft_isdigit('9'));
}

void	test_when_non_digit_then_0(void)
{
	TEST_ASSERT_EQUAL(isdigit('a'), ft_isdigit('a'));
	TEST_ASSERT_EQUAL(isdigit('/'), ft_isdigit('/'));
	TEST_ASSERT_EQUAL(isdigit(':'), ft_isdigit(':'));
	TEST_ASSERT_EQUAL(isdigit(' '), ft_isdigit(' '));
	TEST_ASSERT_EQUAL(isdigit('A'), ft_isdigit('A'));
}
