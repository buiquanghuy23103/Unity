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
	TEST_ASSERT_EQUAL(tolower('#'), ft_tolower('#'));
}
void	test_when_lower_then_no_change(void)
{
	TEST_ASSERT_EQUAL(tolower('a'), ft_tolower('a'));
	TEST_ASSERT_EQUAL(tolower('z'), ft_tolower('z'));
}
void	test_when_upper_then_to_lower(void)
{
	TEST_ASSERT_EQUAL(tolower('A'), ft_tolower('A'));
	TEST_ASSERT_EQUAL(tolower('Z'), ft_tolower('Z'));
}
