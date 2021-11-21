#include "libft.h"
#include "unity.h"
#include "testft.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}
void	test_whenNull_thenNonError(void)
{
	ft_putstr_fd(NULL, 1);
	ft_putstr(NULL);
	ft_putendl_fd(NULL, 1);
	ft_putendl(NULL);
	TEST_ASSERT_EQUAL(1, 1);
}

void	test_when_negative_fd_then_non_error(void)
{
	ft_putchar_fd('a', -1);
	ft_putstr_fd("abc", -1);
	ft_putendl_fd("abc", -1);
	TEST_ASSERT_EQUAL(1, 1);
}

void	test_when_zero_fd_then_print_output(void)
{
	int		fd;
	int		copy_out;
	size_t	size;
	char	*str;
	char	*actual;
	FILE	*file;

	fd = 0;
	copy_out = 0;
	str = "abcd";
	init_redirect(&fd, &copy_out);
	ft_putstr(str);
	reset_output(&copy_out);
	file = fdopen(fd, "r");
	size = file_size(file);
	rewind(file);
	if (size < 0)
		return ;
	actual = (char*)malloc(sizeof(char) * (size + 1));
	fscanf(file, "%s", actual);
	TEST_ASSERT_EQUAL_STRING(str, actual);
	free(actual);
	clean_up(file);
}
