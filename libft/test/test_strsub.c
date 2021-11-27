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
	char	*actual;

	actual = ft_strsub("Hello world!", 3, 0);
	TEST_ASSERT_EMPTY(actual);
	free(actual);
}

void	test_when_start_and_len_valid(void)
{
	char	*actual;

	actual = ft_strsub("Hello world!\n", 6, 5);
	TEST_ASSERT_EQUAL_STRING("world", actual);
	free(actual);
}
