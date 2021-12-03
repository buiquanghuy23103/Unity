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

void	ASSERT_STRTRIM(const char *input, const char *expected)
{
	char	*actual;

	actual = ft_strtrim(input);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
}
void	test_whitespace_the_end(void)
{
	ASSERT_STRTRIM("Hello world! \t\n", "Hello world!");
}
void	test_whitespace_the_beginning(void)
{
	ASSERT_STRTRIM("\t \nHello world!", "Hello world!");
}
void	test_only_whitespace(void)
{
	ASSERT_STRTRIM("\t\n   ", "");
}
