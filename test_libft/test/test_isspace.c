#include "libft.h"
#include "unity.h"
#include "ctype.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_when_white_space_then_1(void)
{
	TEST_ASSERT_EQUAL(isspace(' '), ft_isspace(' '));
	TEST_ASSERT_EQUAL(isspace('\t'), ft_isspace('\t'));
	TEST_ASSERT_EQUAL(isspace('\n'), ft_isspace('\n'));
	TEST_ASSERT_EQUAL(isspace('\v'), ft_isspace('\v'));
	TEST_ASSERT_EQUAL(isspace('\f'), ft_isspace('\f'));
	TEST_ASSERT_EQUAL(isspace('\r'), ft_isspace('\r'));
}

void	test_when_non_white_space_then_0(void)
{
	TEST_ASSERT_EQUAL(isspace('a'), ft_isspace('a'));
	TEST_ASSERT_EQUAL(isspace('A'), ft_isspace('A'));
	TEST_ASSERT_EQUAL(isspace('3'), ft_isspace('3'));
	TEST_ASSERT_EQUAL(isspace('?'), ft_isspace('?'));
	TEST_ASSERT_EQUAL(isspace(']'), ft_isspace(']'));
}
