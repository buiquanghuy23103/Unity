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

void	test_should_return_correct_value(void)
{
	char	s1[] = "Hello \0 1234567890";
	char	s2[] = "Hello \0 1234567890";
	char	s3[] = "world!";

	TEST_ASSERT_EQUAL(strlcat(s1, s3, sizeof(s1)), ft_strlcat(s2, s3, sizeof(s2)));
}

void	test_should_modify_dst_correctly(void)
{
	char	s1[] = "Hello \0 1234567890";
	char	s2[] = "Hello \0 1234567890";
	char	s3[] = "world!";

	ft_strlcat(s1, s3, sizeof(s1));
	strlcat(s2, s3, sizeof(s2));
	TEST_ASSERT_EQUAL_MEMORY(s2, s1, sizeof(s2));
}

void	test_when_dstsize_zero(void)
{
	char	s1[] = "Hello \0 1234567890";
	char	s2[] = "Hello \0 1234567890";
	char	s3[] = "world!";

	TEST_ASSERT_EQUAL(strlcat(s1, s3, sizeof(s1)), ft_strlcat(s2, s3, sizeof(s2)));
	TEST_ASSERT_EQUAL_MEMORY(s2, s1, sizeof(s2));
}

void	test_when_src_too_long_should_truncate_output(void)
{
	char	s1[] = "Hello \0 1234567890";
	char	s2[] = "Hello \0 1234567890";
	char	s3[] = ", my name is QWERTYUIOPASDFGHJKLZXCVBNM,./";

	TEST_ASSERT_EQUAL(strlcat(s1, s3, sizeof(s1)), ft_strlcat(s2, s3, sizeof(s2)));
	TEST_ASSERT_EQUAL_MEMORY(s2, s1, sizeof(s2));
}

void	test_when_dst_string_longer_than_dstsize(void)
{
	char	s1[] = "Hello \0 1234567890";
	char	s2[] = "Hello \0 1234567890";
	char	s3[] = "world!";

	TEST_ASSERT_EQUAL(strlcat(s1, s3, sizeof(s1) - 3), ft_strlcat(s2, s3, sizeof(s2) - 3));
	TEST_ASSERT_EQUAL_MEMORY(s2, s1, sizeof(s2));
}

void	test_when_src_and_dst_string_longer_than_dstsize(void)
{
	char	s1[] = "Hello \0 1234567890";
	char	s2[] = "Hello \0 1234567890";
	char	s3[] = "world!";

	TEST_ASSERT_EQUAL(strlcat(s1, s3, 3), ft_strlcat(s2, s3, 3));
	TEST_ASSERT_EQUAL_MEMORY(s2, s1, sizeof(s2));
}
