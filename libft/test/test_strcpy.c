#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

static void	TEST_ASSERT_STRCPY(size_t str_size, const char *src)
{
	char	*actual;
	char	*expected;

	actual = ft_strnew(str_size);
	expected = ft_strnew(str_size);
	TEST_ASSERT_EQUAL_STRING(actual, ft_strcpy(actual, src));
	strcpy(expected, src);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
	free(expected);
}

void	test_when_src_same_length_as_dst(void)
{
	TEST_ASSERT_STRCPY(7, "Hello !");
}

void	test_when_src_longer_than_dst(void)
{
	TEST_ASSERT_STRCPY(5, "Hello !");
}

void	test_when_src_shorter_than_dst(void)
{
	TEST_ASSERT_STRCPY(20, "Hello !");
}
