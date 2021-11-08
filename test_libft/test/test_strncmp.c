#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_when_s1_null(void)
{
	const char *s1 = NULL;
	const char *s2 = "abc";
	size_t n = 2;
	TEST_ASSERT_EQUAL(strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
}
void	test_when_s1_empty(void)
{
	const char *s1 = "";
	const char *s2 = "abc";
	size_t n = 2;
	TEST_ASSERT_EQUAL(strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
}
void	test_when_s2_null(void)
{
	const char *s1 = "abc";
	const char *s2 = NULL;
	size_t n = 2;
	TEST_ASSERT_EQUAL(strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
}
void	test_when_s2_empty(void)
{
	const char *s1 = "abc";
	const char *s2 = "";
	size_t n = 2;
	TEST_ASSERT_EQUAL(strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
}
void	test_when_n_larger_than_s1(void)
{
	const char *s1 = "abc";
	const char *s2 = "abcde";
	size_t n = 4;
	TEST_ASSERT_EQUAL(strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
}
void	test_when_n_larger_than_s2(void)
{
	const char *s1 = "abcde";
	const char *s2 = "abc";
	size_t n = 4;
	TEST_ASSERT_EQUAL(strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
}
void	test_when_n_zero(void)
{
	const char *s1 = "abc";
	const char *s2 = "abc";
	size_t n = 0;
	TEST_ASSERT_EQUAL(strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
}
void	test_when_s1_partially_equal_s2(void)
{
	const char *s1 = "abcdef";
	const char *s2 = "abcxyz";
	size_t n = 3;
	TEST_ASSERT_EQUAL(strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
}
