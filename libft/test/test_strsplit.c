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

void	test_0(void)
{
	TEST_ASSERT_EQUAL_INT(3, ft_elem_count("*hello*fellow***students*", '*'));
}

void	test_1(void)
{
	char	**actual;
	char	*expected[] = {"hello", "fellow", "students", NULL};


	actual = ft_strsplit("*hello*fellow***students*", '*');
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, 4);
	while(*actual)
	{
		free(*actual);
		actual++;
	}
	free(actual);
}
