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

char	ft_goup(char c)
{
	return ((char) ft_toupper(c));
}

void	test_when_s_empty_then_do_nothing(void)
{
	char	*str;
	str = ft_strmap("", &ft_goup);
	TEST_ASSERT_EMPTY(str);
	ft_strdel(&str);
}

void	test_when_function_ptr_null(void)
{
	char	input[] = "Hello world!";
	char	*str;

	str = ft_strmap(input, NULL);
	TEST_ASSERT_EQUAL_STRING(input, str);
	ft_strdel(&str);
}

void	test_when_long_string(void)
{
	char	input[] = "Hello, my name is Huy!\n";
	char	*str;

	str = ft_strmap(input, &ft_goup);
	TEST_ASSERT_EQUAL_STRING("HELLO, MY NAME IS HUY!\n", str);
	ft_strdel(&str);
}
