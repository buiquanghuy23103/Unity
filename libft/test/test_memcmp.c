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

void	test_1(void)
{
	int	b1[100];
	int	b2[100];

	memset(b1, 300, 100);
	memset(b2, 300, 50);
	memset(b2 + 50, 500, 50);

	TEST_ASSERT_EQUAL(memcmp(b1, b2, 100), ft_memcmp(b1, b2, 100));
	TEST_ASSERT_EQUAL(memcmp(b1, b2, 50), ft_memcmp(b1, b2, 50));
}

void	test_when_zero_in_middle(void)
{
	char	b1[] = "Hei, what's\0 up	";
	char	b2[] = "Hei, what's\0 up ";

	TEST_ASSERT_EQUAL(memcmp(b1, b2, sizeof(b1)), ft_memcmp(b1, b2, sizeof(b1)));
}

void	test_char_200_should_be_larger_than_0(void)
{
	char	b1[] = "Hei, what's\200 up";
	char	b2[] = "Hei, what's\0 up";

	TEST_ASSERT_EQUAL(memcmp(b1, b2, sizeof(b1)), ft_memcmp(b1, b2, sizeof(b1)));
	
}
