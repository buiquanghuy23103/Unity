#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_strlen_whenAbc(void)
{
	TEST_ASSERT_EQUAL(strlen("abc"), ft_strlen("abc"));
}

void	test_strlen_whenEmpty_then0(void)
{
	TEST_ASSERT_EQUAL(strlen(""), ft_strlen(""));
}
