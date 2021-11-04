#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_whenAbc(void)
{
	TEST_ASSERT_EQUAL_STRING(strdup("abc"), ft_strdup("abc"));
}

void	test_whenEmpty(void)
{
	TEST_ASSERT_EQUAL_STRING(strdup(""), ft_strdup(""));
}
