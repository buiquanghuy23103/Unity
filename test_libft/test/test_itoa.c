#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_when_negative_number(void)
{
	int i = -4235;
	TEST_ASSERT_EQUAL_STRING("-4235", ft_itoa(i));
}
void	test_when_zero(void)
{
	int i = 0;
	TEST_ASSERT_EQUAL_STRING("0", ft_itoa(i));
}
void	test_when_positive(void)
{
	int i = 4235;
	TEST_ASSERT_EQUAL_STRING("4235", ft_itoa(i));
}
void	test_when_min_int(void)
{
	int i = -2147483648;
	TEST_ASSERT_EQUAL_STRING("-2147483648", ft_itoa(i));
}
void	test_when_max_int(void)
{
	int i = 2147483647;
	TEST_ASSERT_EQUAL_STRING("2147483647", ft_itoa(i));
}
