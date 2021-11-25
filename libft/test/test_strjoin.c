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

	prefix = "";
	suffix = "Hello world!\n";
	TEST_ASSERT_EQUAL_STRING(suffix, ft_strjoin(prefix, suffix));
}

void	test_when_suffix_empty_then_equal_prefix(void)
{
	char	*prefix;
	char	*suffix;

	prefix = "Hello world!\n";
	suffix = "";
	TEST_ASSERT_EQUAL_STRING(prefix, ft_strjoin(prefix, suffix));
}

void	test_when_both_prefix_suffix_empty(void)
{
	char	*prefix;
	char	*suffix;

	prefix = "";
	suffix = "";
	TEST_ASSERT_EMPTY(ft_strjoin(prefix, suffix));
}

void	test_when_both_prefix_suffix_non_empty(void)
{
	char	*prefix;
	char	*suffix;

	prefix = "How are you? ";
	suffix = "Well, I am fine.\n";
	TEST_ASSERT_EQUAL_STRING("How are you? Well, I am fine.\n", ft_strjoin(prefix, suffix));
}
