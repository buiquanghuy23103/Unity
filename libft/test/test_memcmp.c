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

static void	ASSERT_MEMCMP(void *b1, void *b2, size_t n)
{
	TEST_ASSERT_EQUAL(memcmp(b1, b2, n), ft_memcmp(b1, b2, n));
}

void	test_1(void)
{
	int	b1[100];
	int	b2[100];

	memset(b1, 300, 100);
	memset(b2, 300, 50);
	memset(b2 + 50, 500, 50);

	ASSERT_MEMCMP(b1, b2, 100);
	ASSERT_MEMCMP(b1, b2, 50);
}

void	test_when_zero_in_middle(void)
{
	char	b1[] = "Hei, what's\0 up	";
	char	b2[] = "Hei, what's\0 up ";

	ASSERT_MEMCMP(b1, b2, sizeof(b1));
}

void	test_char_200_should_be_larger_than_0(void)
{
	char	b1[] = "Hei, what's\200 up";
	char	b2[] = "Hei, what's\0 up";

	ASSERT_MEMCMP(b1, b2, sizeof(b1));
}

void	test_should_handle_any_mem_type(void)
{
	char			char1_tab[10];
	char			char2_tab[10];
	int				int1_tab[10];
	int				int2_tab[10];
	unsigned long	long1_tab[10];
	unsigned long	long2_tab[10];
	int				i;

	i = 0;
	while (i < 10)
	{
		char1_tab[i] = (char) rand();
		char2_tab[i] = (char) rand();
		int1_tab[i] = rand();
		int2_tab[i] = rand();
		long1_tab[i] = (unsigned long) rand() * 10000;
		long2_tab[i] = (unsigned long) rand() * 10000;
		i++;
	}

	ASSERT_MEMCMP(char1_tab, char2_tab, 10);
	ASSERT_MEMCMP(int1_tab, int2_tab, 10);
	ASSERT_MEMCMP(long1_tab, long2_tab, 10);
}
