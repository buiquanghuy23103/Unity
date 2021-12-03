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

char	ft_updown(unsigned int i, char c)
{
	if (i % 2 == 0)
		return ((char) ft_toupper(c));
	else
		return ((char) ft_tolower(c));
}

void	test_when_s_empty_then_do_nothing(void)
{
	char	*str;
	str = ft_strmapi("", &ft_updown);
	TEST_ASSERT_EMPTY(str);
	ft_strdel(&str);
}

void	test_when_function_ptr_null(void)
{
	char	input[] = "Hello world!";
	char	*str;

	str = ft_strmapi(input, NULL);
	TEST_ASSERT_EQUAL_STRING(input, str);
	ft_strdel(&str);
}

void	test_when_long_string(void)
{
	char	input[] = "Hello, my name is Huy!\n";
	char	*str;

	str = ft_strmapi(input, &ft_updown);
	TEST_ASSERT_EQUAL_STRING("HeLlO, mY NaMe iS HuY!\n", str);
	ft_strdel(&str);
}
