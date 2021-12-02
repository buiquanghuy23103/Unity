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

void	test_return_value_should_be_dst(void)
{
	char	src[100];
	char	dst[100];

	memset(src, 42, 100);
	memset(dst, 65, 100);
	TEST_ASSERT_EQUAL_PTR(dst, ft_memmove(dst, src, 100));
}

void	test_should_handle_overlap(void)
{
	char	src1[] = "abc def";
	char	*dst1 = src1 + 1;
	char	src2[] = "abc def";
	char	*dst2 = src2 + 1;

	ft_memmove(dst1, src1, 5);
	memmove(dst2, src2, 5);

	TEST_ASSERT_EQUAL_STRING(dst2, dst1);
}

//void	test_when_len_larger_than_src_and_dst(void)
//{
//	char	src1[] = "abc def";
//	char	*dst1 = src1 + 1;
//	char	src2[] = "abc def";
//	char	*dst2 = src2 + 1;
//
//	ft_memmove(dst1, src1, 20);
//	memmove(dst2, src2, 20);
//
//	TEST_ASSERT_EQUAL_STRING(dst2, dst1);
//}

//void	test_when_len_larger_than_dst(void)
//{
//	char	src1[] = "abc def";
//	char	*dst1 = src1 + 4;
//	char	src2[] = "abc def";
//	char	*dst2 = src2 + 4;
//
//	ft_memmove(dst1, src1, 5);
//	memmove(dst2, src2, 5);
//
//	TEST_ASSERT_EQUAL_STRING(dst2, dst1);
//}

void	test_when_len_zero(void)
{
	char	src1[] = "abc def";
	char	*dst1 = src1 + 1;
	char	src2[] = "abc def";
	char	*dst2 = src2 + 1;

	ft_memmove(dst1, src1, 0);
	memmove(dst2, src2, 0);

	TEST_ASSERT_EQUAL_STRING(dst2, dst1);
}
