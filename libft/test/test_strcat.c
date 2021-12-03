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
	char	s1[] = "Hello \0 1234567890";
	char	s2[] = "Hello \0 1234567890";
	char	s3[] = "world!";

	TEST_ASSERT_EQUAL_STRING(strcat(s1, s3), ft_strcat(s2, s3));
}
