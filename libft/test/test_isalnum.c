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
	TEST_ASSERT_EQUAL(isalnum('0'), ft_isalnum('0'));
	TEST_ASSERT_EQUAL(isalnum('1'), ft_isalnum('1'));
	TEST_ASSERT_EQUAL(isalnum('2'), ft_isalnum('2'));
	TEST_ASSERT_EQUAL(isalnum('3'), ft_isalnum('3'));
	TEST_ASSERT_EQUAL(isalnum('4'), ft_isalnum('4'));
	TEST_ASSERT_EQUAL(isalnum('5'), ft_isalnum('5'));
	TEST_ASSERT_EQUAL(isalnum('6'), ft_isalnum('6'));
	TEST_ASSERT_EQUAL(isalnum('7'), ft_isalnum('7'));
	TEST_ASSERT_EQUAL(isalnum('8'), ft_isalnum('8'));
	TEST_ASSERT_EQUAL(isalnum('9'), ft_isalnum('9'));
}

void	test_when_lowcase_alpha(void)
{
	char a = 'a';
	TEST_ASSERT_EQUAL(isalnum(a), ft_isalnum(a));
	TEST_ASSERT_EQUAL(isalnum('z'), ft_isalnum('z'));
	TEST_ASSERT_EQUAL(isalnum('m'), ft_isalnum('m'));
}
void	test_when_uppercase_alpha(void)
{
	TEST_ASSERT_EQUAL(isalnum('A'), ft_isalnum('A'));
	TEST_ASSERT_EQUAL(isalnum('Z'), ft_isalnum('Z'));
	TEST_ASSERT_EQUAL(isalnum('M'), ft_isalnum('M'));
}
void	test_when_non_alpha_num(void)
{
	TEST_ASSERT_EQUAL(isalnum('@'), ft_isalnum('@'));
	TEST_ASSERT_EQUAL(isalnum('`'), ft_isalnum('`'));
	TEST_ASSERT_EQUAL(isalnum('['), ft_isalnum('['));
	TEST_ASSERT_EQUAL(isalnum('{'), ft_isalnum('{'));
}
