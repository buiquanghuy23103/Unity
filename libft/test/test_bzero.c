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

void	test_when_n_positive_then_bzero_char(void)
{
	char	*input;
	char	str[10];

	input = "Hello!\n";
	strcpy(str, input);
	ft_bzero(str, 3);
	TEST_ASSERT_EQUAL_CHAR('\0', str[0]);
	TEST_ASSERT_EQUAL_CHAR('\0', str[1]);
	TEST_ASSERT_EQUAL_CHAR('\0', str[2]);
	TEST_ASSERT_EQUAL_CHAR('l', str[3]);
	TEST_ASSERT_EQUAL_CHAR('o', str[4]);
	TEST_ASSERT_EQUAL_CHAR('!', str[5]);
	TEST_ASSERT_EQUAL_CHAR('\n', str[6]);
}

void	test_1(void)
{
	char	b1[] = "Hello world!";
	char	b2[] = "Hello world!";

	ft_bzero(b1, sizeof(b1));
	bzero(b2, sizeof(b2));

	TEST_ASSERT_EQUAL_MEMORY(b2, b1, sizeof(b2));
}

void	test_when_mem_is_int_array(void)
{
	int	b1[100];
	int	b2[100];

	memset(b1, INT_MAX, 100);
	memset(b2, INT_MAX, 100);

	ft_bzero(b1, sizeof(b1));
	bzero(b2, sizeof(b2));

	TEST_ASSERT_EQUAL_MEMORY(b2, b1, sizeof(b2));
}

void	test_when_n_zero_then_do_nothing(void)
{
	char	*input;
	char	str[10];

	input = "Hello!\n";
	strcpy(str, input);
	ft_bzero(str, 0);
	TEST_ASSERT_EQUAL_STRING(input, str);
}
