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

static void ASSERT_STRNCPY(size_t len)
{
	char	src[] = "Hei, how are you?";
	char	actual[100];
	char	expected[100];

	memset(actual, 85, 100);
	memset(expected, 85, 100);
	TEST_ASSERT_EQUAL_MEMORY(
		strncpy(expected, src, len), 
		ft_strncpy(actual, src, len),
		100);
}

void	test_should_return_dst(void)
{
	char	src[] = "Hello world!";
	char	dst[] = "Hey, how are you?";

	TEST_ASSERT_EQUAL_PTR(dst, ft_strncpy(dst, src, 9));
}

void	test_src_less_than_len(void)
{
	ASSERT_STRNCPY(50);
}

void	test_src_larger_than_len(void)
{
	ASSERT_STRNCPY(5);
}
