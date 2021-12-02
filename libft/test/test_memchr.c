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

static void	ASSERT_MEMCHR(void *src, int c, size_t n)
{
	TEST_ASSERT_EQUAL_PTR(memchr(src, c, n), ft_memchr(src, c, n));
}

void	test_when_char_c_found(void)
{
	char	src[] = "Hello world!";

	ASSERT_MEMCHR(src, 'l', 10);
}

void	test_when_char_c_not_found(void)
{
	char	src[] = "Hello world!";

	ASSERT_MEMCHR(src, '=', 10);
}

void	test_when_char_c_zero(void)
{
	char	src[] = "hello world!";

	ASSERT_MEMCHR(src, 0, 20);
}

void	test_when_char_c_not_found_within_range_n(void)
{
	char	src[] = "Hello world!";

	ASSERT_MEMCHR(src, '!', 10);
}

void	test_when_range_n_too_large(void)
{
	char	src[] = "Hello world!";

	ASSERT_MEMCHR(src, 'y', 100);
}

void	test_should_handle_unsigned_char(void)
{
	char			char_tab[10];
	int				int_tab[10];
	unsigned long	long_tab[10];
	int				i;

	i = 0;
	while (i < 10)
	{
		char_tab[i] = (char) rand();
		int_tab[i] = rand();
		long_tab[i] = (unsigned long) rand() * 10000;
		i++;
	}

	ASSERT_MEMCHR(char_tab, char_tab[7], sizeof(char_tab));
	ASSERT_MEMCHR(int_tab, int_tab[7], sizeof(int_tab));
	ASSERT_MEMCHR(long_tab, rand(), sizeof(long_tab));
}

void	test_all_zero(void)
{
	ASSERT_MEMCHR(NULL, 0, 0);
}
