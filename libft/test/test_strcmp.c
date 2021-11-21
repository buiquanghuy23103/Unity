#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_when_s1_equal_s2(void)
{
	const char *s1 = "abc";
	const char *s2 = "abc";
	TEST_ASSERT_EQUAL(strcmp(s1, s2), ft_strcmp(s1, s2));
}

void	test_when_s1_larger_s2(void)
{
	const char *s1 = "abz";
	const char *s2 = "abc";
	TEST_ASSERT_EQUAL(strcmp(s1, s2), ft_strcmp(s1, s2));
}

void	test_when_s1_less_s2(void)
{
	const char *s1 = "ab1";
	const char *s2 = "abc";
	TEST_ASSERT_EQUAL(strcmp(s1, s2), ft_strcmp(s1, s2));
}

void	test_when_s1_longer_s2(void)
{
	const char *s1 = "abcd";
	const char *s2 = "abc";
	TEST_ASSERT_EQUAL(strcmp(s1, s2), ft_strcmp(s1, s2));
}

void	test_when_s1_shorter_s2(void)
{
	const char *s1 = "ab";
	const char *s2 = "abc";
	TEST_ASSERT_EQUAL(strcmp(s1, s2), ft_strcmp(s1, s2));
}
