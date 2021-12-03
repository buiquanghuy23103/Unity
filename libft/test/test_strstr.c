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

static void	ASSERT_STRSTR(char *haystack, char *needle)
{
	TEST_ASSERT_EQUAL_STRING(strstr(haystack, needle), ft_strstr(haystack, needle));
}

void	test_normal_needle(void)
{
	char	haystack[] = "Hey my name is Huy. What is you name?";
	char	needle[] = "name is Huy.";

	ASSERT_STRSTR(haystack, needle);
}

void	test_needle_is_empty_string(void)
{
	char	haystack[] = "Hey my name is Huy. What is you name?";
	char	needle[] = "";

	ASSERT_STRSTR(haystack, needle);
}

void	test_needle_not_found(void)
{
	char	haystack[] = "Hey my name is Huy. What is you name?";
	char	needle[] = "name is Huy Bui.";

	ASSERT_STRSTR(haystack, needle);
}
