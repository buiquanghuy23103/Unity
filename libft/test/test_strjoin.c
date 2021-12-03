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

void	test_when_prefix_empty_then_equal_suffix(void)
{
	char	*prefix;
	char	*suffix;
	char	*actual;

	prefix = "";
	suffix = "Hello world!\n";
	actual = ft_strjoin(prefix, suffix);
	TEST_ASSERT_EQUAL_STRING(suffix, actual);
	free(actual);
}

void	test_when_suffix_empty_then_equal_prefix(void)
{
	char	*prefix;
	char	*suffix;
	char	*actual;

	prefix = "Hello world!\n";
	suffix = "";
	actual = ft_strjoin(prefix, suffix);
	TEST_ASSERT_EQUAL_STRING(prefix, actual);
	free(actual);
}

void	test_when_both_prefix_suffix_empty(void)
{
	char	*prefix;
	char	*suffix;
	char	*actual;

	prefix = "";
	suffix = "";
	actual = ft_strjoin(prefix, suffix);
	TEST_ASSERT_EMPTY(actual);
	free(actual);
}

void	test_when_both_prefix_suffix_non_empty(void)
{
	char	*prefix;
	char	*suffix;
	char	*actual;

	prefix = "How are you? ";
	suffix = "Well, I am fine.\n";
	actual = ft_strjoin(prefix, suffix);
	TEST_ASSERT_EQUAL_STRING("How are you? Well, I am fine.\n", actual);
	free(actual);
}
