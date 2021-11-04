#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_when_src_same_length_as_dst(void)
{
	const char *src = "abc";
	char *dst = (char *)malloc((strlen(src) + 1) * sizeof(char));
	TEST_ASSERT_EQUAL_STRING(strcpy(dst, src), ft_strcpy(dst, src));
}

void	test_when_src_longer_than_dst(void)
{
	const char *src = "abcd";
	char *dst = (char *)malloc((strlen(src) - 1) * sizeof(char));
	TEST_ASSERT_EQUAL_STRING(strcpy(dst, src), ft_strcpy(dst, src));
}

void	test_when_src_shorter_than_dst(void)
{
	const char *src = "abcd";
	char *dst = (char *)malloc((strlen(src) + 3) * sizeof(char));
	TEST_ASSERT_EQUAL_STRING(strcpy(dst, src), ft_strcpy(dst, src));
}
