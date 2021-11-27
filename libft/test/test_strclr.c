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

void	test_when_clear_empty_str(void)
{
	char	*mem;
	size_t	size;
	size_t	i;

	size = 6;
	i = 0;
	mem = ft_strnew(size);
	ft_strclr(mem);
	while (i < size)
	{
		TEST_ASSERT_EQUAL_CHAR('\0', mem[i]);
		i++;
	}
	free(mem);
}

void	test_when_clear_long_str(void)
{
	size_t	i;
	size_t	size;

	char str[] = "Hello, this is a long string.\n";
	size = ft_strlen(str);
	i = 0;
	ft_strclr(str);
	while (i < size)
	{
		TEST_ASSERT_EQUAL_CHAR('\0', str[i]);
		i++;
	}
}
