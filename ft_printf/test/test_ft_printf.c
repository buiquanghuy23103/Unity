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

void	test0()
{
	int		fd = 0;
	int		copy_out = 0;
	char	expected[] = "Hello world!";

	init_redirect(&fd, &copy_out);
	ft_printf(expected);
	reset_output(&copy_out);
	TEST_ASSERT_FILE_CONTENT(expected, fd);
}
