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

void	test_when_size_too_big_then_null(void)
{
	char	*actual;

	actual = ft_strnew(ULONG_MAX);
	TEST_ASSERT_NULL(actual);
	free(actual);
}

void	test_when_size_6_then_empty_new_str(void)
{
	char	*mem;
	size_t	size;
	size_t	i;

	size = 6;
	i = 0;
	mem = ft_strnew(size);
	while (i < size)
	{
		TEST_ASSERT_EQUAL_CHAR('\0', mem[i]);
		i++;
	}
	free(mem);
}
