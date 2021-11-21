#include "libft.h"
#include "unity.h"
#include "ctype.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_when_lowcase_alpha(void)
{
	char a = 'a';
	TEST_ASSERT_EQUAL(isalpha(a), ft_isalpha(a));
	TEST_ASSERT_EQUAL(isalpha('z'), ft_isalpha('z'));
	TEST_ASSERT_EQUAL(isalpha('m'), ft_isalpha('m'));
}
void	test_when_uppercase_alpha(void)
{
	TEST_ASSERT_EQUAL(isalpha('A'), ft_isalpha('A'));
	TEST_ASSERT_EQUAL(isalpha('Z'), ft_isalpha('Z'));
	TEST_ASSERT_EQUAL(isalpha('M'), ft_isalpha('M'));
}
void	test_when_non_alpha(void)
{
	TEST_ASSERT_EQUAL(isalpha('@'), ft_isalpha('@'));
	TEST_ASSERT_EQUAL(isalpha('`'), ft_isalpha('`'));
	TEST_ASSERT_EQUAL(isalpha('9'), ft_isalpha('9'));
	TEST_ASSERT_EQUAL(isalpha('['), ft_isalpha('['));
	TEST_ASSERT_EQUAL(isalpha('{'), ft_isalpha('{'));
}
