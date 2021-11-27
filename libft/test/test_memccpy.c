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

static void	ASSERT_MEMCCPY(int c, size_t n)
{
	char	src[] = "Hello world!";
	char	actual[100];
	void	*actual_ptr;
	char	expected[100];
	void	*expected_ptr;

	actual_ptr = ft_memccpy(actual, src, c, n);
	expected_ptr = memccpy(actual, src, c, n);
	TEST_ASSERT_EQUAL_PTR(expected_ptr, actual_ptr);

	expected_ptr = memccpy(expected, src, c, n);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void	test_char_c_found(void)
{
	ASSERT_MEMCCPY('o', 4);
}
void	test_char_c_not_found(void)
{
	ASSERT_MEMCCPY('z', 4);
}

void	test_char_c_null(void)
{
	ASSERT_MEMCCPY(0, 4);
}
void	test_char_c_null_and_n_zero(void)
{
	ASSERT_MEMCCPY(0, 0);
}
