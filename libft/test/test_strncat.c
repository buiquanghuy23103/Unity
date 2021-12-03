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

void	test_1(void)
{
	char	s1[] = "Hello\0 1234567890";
	char	s2[] = "Hello\0 1234567890";
	char	s3[] = "world!";

	TEST_ASSERT_EQUAL_STRING(strncat(s1, s3, 4), ft_strncat(s2, s3, 4));
}

void	test_2(void)
{
	char	s1[] = "Hello\0 1234567890";
	char	s2[] = "Hello\0 1234567890";
	char	s3[] = "world!";

	TEST_ASSERT_EQUAL_STRING(strncat(s1, s3, 9), ft_strncat(s2, s3, 9));
}

void	test_3(void)
{
	char	s1[] = "Hello\0 1234567890";
	char	s2[] = "Hello\0 1234567890";
	char	s3[] = "world!";

	TEST_ASSERT_EQUAL_STRING(strncat(s1, s3, 0), ft_strncat(s2, s3, 0));
}

