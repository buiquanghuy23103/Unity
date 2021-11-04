#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}
void	test_strlen_whenAbc_then3(void)
{
	TEST_ASSERT_EQUAL(3, ft_strlen("abc"));
}

void	test_strlen_whenNull_then0(void)
{
	TEST_ASSERT_EQUAL(0, ft_strlen(0));
}

void	test_strlen_whenEmpty_then0(void)
{
	TEST_ASSERT_EQUAL(0, ft_strlen(""));
}
