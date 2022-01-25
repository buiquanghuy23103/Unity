#include "libft.h"
#include "unity.h"
#include "testft.h"
#include "ctype.h"
#include "string.h"
#include "stdlib.h"
#include "ft_printf.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_only_format_str(void)
{
	int		fd = 0;
	int		copy_out = 0;
	char	expected[] = "Hello world!";

	init_redirect(&fd, &copy_out);
	ft_printf(expected);
	reset_output(&copy_out);
	TEST_ASSERT_FILE_CONTENT(expected, fd);
}

void	test_one_str_var(void)
{
	int		fd = 0;
	int		copy_out = 0;
	char	expected[] = "Hello world! I am Huy";

	init_redirect(&fd, &copy_out);
	ft_printf("Hello world! %s", "I am Huy");
	reset_output(&copy_out);
	TEST_ASSERT_FILE_CONTENT(expected, fd);
}

void	test_three_str_var(void)
{
	int		fd = 0;
	int		copy_out = 0;
	char	expected[] = "Hello world! one, two, three";

	init_redirect(&fd, &copy_out);
	ft_printf("Hello world! %s, %s, %s", "one", "two", "three");
	reset_output(&copy_out);
	TEST_ASSERT_FILE_CONTENT(expected, fd);
}

void	test_number_var(void)
{
	int		fd = 0;
	int		copy_out = 0;
	char	expected[] = "Hello world! 1, -2, 30000";

	init_redirect(&fd, &copy_out);
	ft_printf("Hello world! %d, %d, %d", 1, -2, 30000);
	reset_output(&copy_out);
	TEST_ASSERT_FILE_CONTENT(expected, fd);
}

void	test_char_var(void)
{
	int		fd = 0;
	int		copy_out = 0;
	char	expected[] = "Hello world! a b c";

	init_redirect(&fd, &copy_out);
	ft_printf("Hello world! %c %c %c", 'a', 'b', 'c');
	reset_output(&copy_out);
	TEST_ASSERT_FILE_CONTENT(expected, fd);
}
