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
	void	*actual;
	void	*expected;
	size_t	size;

	size = 100;
	actual = ft_memalloc(size);
	expected = calloc(size, 1);
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(expected, actual, size, "simple test");
	free(actual);
	free(expected);
}

void	test_2(void)
{
	void	*actual;

	actual = ft_memalloc(ULONG_MAX);
	TEST_ASSERT_NULL(actual);
	free(actual);
}
