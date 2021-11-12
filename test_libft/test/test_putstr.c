#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}
void	test_whenNull_thenNonError(void)
{
	ft_putstr_fd(NULL, 1);
	ft_putstr(NULL);
	ft_putendl_fd(NULL, 1);
	ft_putendl(NULL);
	TEST_ASSERT_EQUAL(1, 1);
}

void	test_when_negative_fd_then_non_error(void)
{
	ft_putchar_fd('a', -1);
	ft_putstr_fd("abc", -1);
	ft_putendl_fd("abc", -1);
	TEST_ASSERT_EQUAL(1, 1);
}
