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
void	test_when_non_alpha_then_no_change(void)
{
	TEST_ASSERT_EQUAL(toupper('#'), ft_toupper('#'));
}
void	test_when_upper_then_no_change(void)
{
	TEST_ASSERT_EQUAL(toupper('A'), ft_toupper('A'));
	TEST_ASSERT_EQUAL(toupper('Z'), ft_toupper('Z'));
}
void	test_when_lower_then_to_upper(void)
{
	TEST_ASSERT_EQUAL(toupper('a'), ft_toupper('a'));
	TEST_ASSERT_EQUAL(toupper('z'), ft_toupper('z'));
}
