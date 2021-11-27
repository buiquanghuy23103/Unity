#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

static void	TEST_ASSERT_STRDUP(char *str)
{
	char	*actual;
	char	*expected;

	actual = ft_strdup(str);
	expected = strdup(str);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
	free(expected);
}

void	test_whenAbc(void)
{
	TEST_ASSERT_STRDUP("Hello world!\n");
}

void	test_whenEmpty(void)
{
	TEST_ASSERT_STRDUP("");
}
