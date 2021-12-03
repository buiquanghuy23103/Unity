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

void	test_when_memdel_then_ptr_null(void)
{
	int		*mem;

	mem = (int *)malloc(sizeof(int) * 3);
	mem[0] = 949;
	mem[1] = 859;
	mem[2] = 442;
	ft_memdel((void **)&mem);
	TEST_ASSERT_NULL(mem);
}
