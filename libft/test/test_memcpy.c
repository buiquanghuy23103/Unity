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

void	test_when_cpy_then_identical(void)
{
	char	b1[100];
	char	b2[100];

	memset(b1, 42, 100);
	memset(b2, 65, 100);

	ft_memcpy(b1, b2, 100);
	TEST_ASSERT_EQUAL_INT(0, memcmp(b1, b2, 100));
	TEST_ASSERT_EQUAL_INT(0, memcmp(b1, ft_memcpy(b1, b2, 100), 100));
}
