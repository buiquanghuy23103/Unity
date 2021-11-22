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

void	test_when_size_0_then_do_nothing(void)
{
	ft_memalloc(0);
	TEST_PASS();
}

void	test_when_size_6_then_allocate_mem_fresh(void)
{
	char	*mem;
	size_t	size;
	size_t	i;

	size = 6;
	i = 0;
	mem = (char *) ft_memalloc(size);
	while (i < size)
	{
		TEST_ASSERT_EQUAL_CHAR('\0', mem[i]);
		i++;
	}
}
