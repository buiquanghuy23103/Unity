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

void	test_when_both_empty_then_true(void)
{
	TEST_ASSERT_TRUE(ft_strnequ("", "", 5));
}

void	test_when_both_null_then_true(void)
{
	TEST_ASSERT_TRUE(ft_strnequ(NULL, NULL, 7));
}

void	test_when_s1_null_s2_non_null_then_false(void)
{
	TEST_ASSERT_FALSE(ft_strnequ(NULL, "Akd lw", 9));
}

void	test_when_s1_non_null_s2_null_then_false(void)
{
	TEST_ASSERT_FALSE(ft_strnequ("Hello workd", NULL, 1));
}

void	test_when_identical_then_true(void)
{
	TEST_ASSERT_TRUE(ft_strnequ("Hello World!\n","Hello !\n", 6));
}

void	test_when_different_then_false(void)
{
	TEST_ASSERT_FALSE(ft_strnequ("Hello World!\n","Hello world!\n", 7));
}

void	test_when_s1_s2_identical_but_n_larger_than_both_then_true(void)
{
	TEST_ASSERT_TRUE(ft_strnequ("Hello !\n","Hello !\n", 10));
}

void	test_when_n_zero(void)
{
	TEST_ASSERT_TRUE(ft_strnequ("Hello!", "Hi", 0));
}

void	test_when_s1_longer_than_n_longer_than_s2_then_false(void)
{
	TEST_ASSERT_FALSE(ft_strnequ("Hello World!\n","Hello", 6));
}
