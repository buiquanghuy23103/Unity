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

void	ft_print_upper(char	*c)
{
	*c = (char) ft_toupper(*c);
}

void	test_when_s_empty_then_do_nothing(void)
{
	ft_striter("", &ft_print_upper);
	TEST_PASS();
}

void	test_when_function_ptr_null(void)
{
	ft_striter("Hello world!", NULL);
	TEST_PASS();
}

void	test_when_long_string(void)
{
	char str[] = "Hello, my name is Huy!\n";

	ft_striter(str, &ft_print_upper);
	TEST_ASSERT_EQUAL_STRING("HELLO, MY NAME IS HUY!\n", str);
}
