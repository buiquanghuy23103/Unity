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

static void	ASSERT_STRNSTR(char *haystack, char *needle, size_t len)
{
	TEST_ASSERT_EQUAL_STRING(strnstr(haystack, needle, len), ft_strnstr(haystack, needle, len));
}

void	test_normal_needle(void)
{
	char	haystack[] = "Hey my name is Huy. What is you name?";
	char	needle[] = "name is Huy.";

	ASSERT_STRNSTR(haystack, needle, strlen(haystack));
}

void	test_needle_is_empty_string(void)
{
	char	haystack[] = "Hey my name is Huy. What is you name?";
	char	needle[] = "";

	ASSERT_STRNSTR(haystack, needle, strlen(haystack));
}

void	test_needle_not_found(void)
{
	char	haystack[] = "Hey my name is Huy. What is you name?";
	char	needle[] = "name is Huy Bui.";

	ASSERT_STRNSTR(haystack, needle, strlen(haystack));
}

void	test_when_needle_found_but_len_too_small(void)
{
	char	haystack[] = "Hey my name is Huy. What is you name?";
	char	needle[] = "name is Huy.";

	ASSERT_STRNSTR(haystack, needle, strlen(needle));
}

void	test_when_needle_found_but_len_just_big_enough(void)
{
	char	haystack[] = "name is Huy. What is you name?";
	char	needle[] = "name is Huy.";

	ASSERT_STRNSTR(haystack, needle, strlen(needle));
}

void	test_basic_input(void)
{
	char	haystack[] = "Hello les genw";
	char	needle[] = "Hello";

	ASSERT_STRNSTR(haystack, needle, 3);
}
