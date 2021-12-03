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

void	test_when_strdel_then_ptr_null(void)
{
	char	*mem;

	mem = (char *)malloc(sizeof(int) * 14);
	strcpy(mem, "Hello world!\n");
	ft_strdel(&mem);
	TEST_ASSERT_NULL(mem);
}
