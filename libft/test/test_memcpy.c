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

void	test_when_cpy_whole_str(void)
{
	char	*src;
	char	*dst;

	src = "This is a test.\n";
	dst = (char *)ft_memalloc((ft_strlen(src) + 1) * sizeof(char));
	ft_memcpy(dst, src, 16);
	dst[16] = '\0';
	TEST_ASSERT_EQUAL_STRING(src, dst);
}

void	test_when_cpy_partially_str(void)
{
	const char	*src;
	char	*actual;

	src = "This is a test.\n";
	actual = (char *)ft_memalloc((ft_strlen(src) + 1) * sizeof(char));
	ft_memcpy(actual, src, 10);
	actual[10] = '\0';

	TEST_ASSERT_EQUAL_STRING("This is a ", actual);
	free(actual);
}
