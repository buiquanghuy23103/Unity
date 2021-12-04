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

static void	ASSERT_MEMSET(void *expected, void *actual, int c, size_t n)
{
	memset(expected, c, n);
	ft_memset(actual, c, n);
	TEST_ASSERT_EQUAL_MEMORY(expected, actual, n);
}

void	test_when_change_three_char(void)
{
	char	input_expected[40];
	char	input_actual[40];
	char	*expected;
	char	*actual;

	strcpy(input_expected, "Hello world!\n");
	strcpy(input_actual, "Hello world!\n");
	expected = (char*) memset(input_expected, 'z', 3);
	actual = (char*) ft_memset(input_actual, 'z', 3);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void	test_when_size_zero(void)
{
	char	input_expected[40];
	char	input_actual[40];
	char	*expected;
	char	*actual;

	strcpy(input_expected, "Hello world!\n");
	strcpy(input_actual, "Hello world!\n");
	expected = (char*) memset(input_expected, 'z', (0));
	actual = (char*) ft_memset(input_actual, 'z', (0));
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void	test_when_mem_is_integer_array(void)
{
	int		tab1[100];
	int		tab2[100];

	ft_memset(tab1, 99, 100);
	memset(tab2, 99, 100);

	TEST_ASSERT_EQUAL_MEMORY(tab2, tab1, 100);
}

void	test_when_mem_is_unsigned_long(void)
{
	unsigned long		tab1[100];
	unsigned long		tab2[100];

	ft_memset(tab1, 99, 100);
	memset(tab2, 99, 100);

	TEST_ASSERT_EQUAL_MEMORY(tab2, tab1, 100);
}

void	test_when_mem_is_string(void)
{
	char	tab1[100];
	char	tab2[100];

	ft_memset(tab1, 99, 100);
	memset(tab2, 99, 100);

	TEST_ASSERT_EQUAL_MEMORY(tab2, tab1, 100);
}

void	test_when_set_value_is_int_max(void)
{
	int		tab1[100];
	int		tab2[100];

	ft_memset(tab1, INT_MAX, 100);
	memset(tab2, INT_MAX, 100);

	TEST_ASSERT_EQUAL_MEMORY(tab2, tab1, 100);
}

void	test_when_set_value_is_uchar_max(void)
{
	char	tab1[100];
	char	tab2[100];

	ft_memset(tab1, UCHAR_MAX, 100);
	memset(tab2, UCHAR_MAX, 100);

	TEST_ASSERT_EQUAL_MEMORY(tab2, tab1, 100);
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

	ASSERT_MEMSET(char1_tab, char2_tab, 1000, 10);
	ASSERT_MEMSET(int1_tab, int2_tab, INT_MAX, 10);
	ASSERT_MEMSET(long1_tab, long2_tab, 12345, 10);
}
