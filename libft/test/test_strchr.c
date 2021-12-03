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

static void	ASSERT_STRCHR(void *src, int c)
{
	TEST_ASSERT_EQUAL_PTR(strchr(src, c), ft_strchr(src, c));
}

void	test_when_char_c_found(void)
{
	char	src[] = "Hello world!";

	ASSERT_STRCHR(src, 'l');
}

void	test_when_char_c_not_found(void)
{
	char	src[] = "Hello world!";

	ASSERT_STRCHR(src, '=');
}

void	test_when_char_c_zero(void)
{
	char	src[] = "hello world!";

	ASSERT_STRCHR(src, 0);
}

void	test_when_char_c_not_found_within_range_n(void)
{
	char	src[] = "Hello world!";

	ASSERT_STRCHR(src, '!');
}

void	test_when_range_n_too_large(void)
{
	char	src[] = "Hello world!";

	ASSERT_STRCHR(src, 'y');
}

void	test_empty_string_and_null_char(void)
{
	ASSERT_STRCHR("", 0);
}

void	test_null_string(void)
{
	ASSERT_STRCHR(NULL, 'h');
}
