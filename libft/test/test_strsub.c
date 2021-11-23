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

void	test_when_len_zero_then_null(void)
{
	TEST_ASSERT_EMPTY(ft_strsub("Hello world!", 3, 0));
}

void	test_when_start_and_len_valid(void)
{
	TEST_ASSERT_EQUAL_STRING("world", ft_strsub("Hello world!\n", 6, 5));
}
