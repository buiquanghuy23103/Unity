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

static void	ASSERT_MEMCCPY_PTR(char *src, int c, size_t n)
{
	char	dst[] = "This is a very long long long senctence.\n";
	TEST_ASSERT_EQUAL_STRING_MESSAGE(
		memccpy(dst, src, c, n),
		ft_memccpy(dst, src, c, n),
		"Should return correct pointer"
	);
}

static void	ASSERT_MEMCCPY_DST(char *src, int c, size_t n)
{
	char	actual[] = "This is a very long long long senctence.\n";
	char	expected[] = "This is a very long long long senctence.\n";
	
	ft_memccpy(actual, src, c, n);
	memccpy(expected, src, c, n);
	TEST_ASSERT_EQUAL_STRING_MESSAGE(
		expected,
		actual,
		"Should modify dst correctly"
	);
}

static void	ASSERT_MEMCCPY(char *src, int c, size_t n)
{
	ASSERT_MEMCCPY_PTR(src, c, n);
	ASSERT_MEMCCPY_DST(src, c, n);
}

void	test_char_c_found(void)
{
	char	src[] = "Hello world!";
	ASSERT_MEMCCPY(src, 'o', 10);
}
void	test_char_c_not_found(void)
{
	char	src[] = "Hello world!";
	ASSERT_MEMCCPY(src, 'z', 10);
}

void	test_char_c_null(void)
{
	char	src[] = "Hello world!";
	ASSERT_MEMCCPY(src, 0, 10);
}
void	test_char_c_null_and_n_zero(void)
{
	char	src[] = "Hello world!";
	ASSERT_MEMCCPY(src, 0, 0);
}
void	test_char_c_null_and_n_equal_src_len(void)
{
	char	src[] = "Hello world!";
	ASSERT_MEMCCPY(src, 0, sizeof(src));
}
void	test_char_c_is_first_char_in_src(void)
{
	char	src[] = "Hello world!";
	ASSERT_MEMCCPY(src, 'H', 10);
}
void	test_char_c_should_be_unsigned_char(void)
{
	char	src[] = "Well, \200 is larger than";
	ASSERT_MEMCCPY(src, '\200', 20);
}
void	test_char_c_found_and_n_is_reached_before_c(void)
{
	char	src[] = "Well, \200 is larger than";
	ASSERT_MEMCCPY(src, '\200', 4);
}
void	test_when_n_is_one_char_far_from_c(void)
{
	char src[] = "string withAinside !";
	ASSERT_MEMCCPY(src, 'A', 11);
}
