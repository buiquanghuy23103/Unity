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

static void	ASSERT_STRRCHR(void *src, int c)
{
	TEST_ASSERT_EQUAL_PTR(strrchr(src, c), ft_strrchr(src, c));
}

void	test_when_char_c_found(void)
{
	char	src[] = "Hello world!";

	ASSERT_STRRCHR(src, 'l');
}

void	test_when_char_c_not_found(void)
{
	char	src[] = "Hello world!";

	ASSERT_STRRCHR(src, '=');
}

void	test_when_char_c_zero(void)
{
	char	src[] = "hello world!";

	ASSERT_STRRCHR(src, 0);
}

void	test_when_char_c_not_found_within_range_n(void)
{
	char	src[] = "Hello world!";

	ASSERT_STRRCHR(src, '!');
}

void	test_when_range_n_too_large(void)
{
	char	src[] = "Hello world!";

	ASSERT_STRRCHR(src, 'y');
}

void	test_empty_string_and_null_char(void)
{
	ASSERT_STRRCHR("", 0);
}
//
//void	test_null_string(void)
//{
//	ASSERT_STRRCHR(NULL, 'h');
//}
