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

void	ft_print_updown(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = (char) ft_toupper(*c);
	else
		*c = (char) ft_tolower(*c);
}

void	test_when_s_empty_then_do_nothing(void)
{
	ft_striteri("", &ft_print_updown);
	TEST_PASS();
}

void	test_when_function_ptr_null(void)
{
	ft_striteri("Hello world!", NULL);
	TEST_PASS();
}

void	test_when_long_string(void)
{
	char str[] = "Hello, my name is Huy!\n";

	ft_striteri(str, &ft_print_updown);
	TEST_ASSERT_EQUAL_STRING("HeLlO, mY NaMe iS HuY!\n", str);
}
