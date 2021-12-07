#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

static void	TEST_ASSERT_STRNCMP(char *s1, char *s2, size_t n)
{
	TEST_ASSERT_EQUAL(strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
}

void	test_when_s1_empty(void)
{
	TEST_ASSERT_STRNCMP("", "abc", 2);
}
void	test_when_s2_empty(void)
{
	TEST_ASSERT_STRNCMP("abc", "", 2);
}
void	test_when_n_larger_than_s1(void)
{
	TEST_ASSERT_STRNCMP("Hello ", "Hello world!\n", 8);
}
void	test_when_n_larger_than_s2(void)
{
	TEST_ASSERT_STRNCMP("helllo world!", "hello", 8);
}
void	test_when_n_zero(void)
{
	TEST_ASSERT_STRNCMP("Hello world", "Hello world!", 0);
}
void	test_when_s1_partially_equal_s2(void)
{
	TEST_ASSERT_STRNCMP("Hello world!", "HellZ world!", 6);
}
void	test_unsigned_char_conversion(void)
{
	TEST_ASSERT_STRNCMP("\200", "\0", 1);
}
void	test_basic_input(void)
{
	TEST_ASSERT_STRNCMP("cba", "abc", 2);
}
