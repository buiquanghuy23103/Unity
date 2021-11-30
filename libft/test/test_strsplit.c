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

static void	ASSERT_STRSPLIT(char *expected[], char *src, char c, int array_len)
{
	int		i;
	char	**actual;

	i = 0;
	actual = ft_strsplit(src, c);
	while(i < array_len)
	{
		TEST_ASSERT_EQUAL_STRING(expected[i], actual[i]);
		i++;
	}
}

void	test_1(void)
{
	char	*expected[] = {"hello", "fellow", "students", NULL};
	char	src[] = "*hello*fellow***students*";

	ASSERT_STRSPLIT(expected, src, '*', 4); 
}

void	test_no_char_c_at_beginning(void)
{
	char	*expected[] = {"hello", "fellow", "students", NULL};
	char	src[] = "hello*fellow***students*";

	ASSERT_STRSPLIT(expected, src, '*', 4); 
}

void	test_no_char_c(void)
{
	char	*expected[] = {"hello fellow students.", NULL};
	char	src[] = "hello fellow students.";

	ASSERT_STRSPLIT(expected, src, '*', 2); 
}
