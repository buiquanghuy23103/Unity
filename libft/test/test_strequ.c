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
	TEST_ASSERT_TRUE(ft_strequ("", ""));
}

void	test_when_both_null_then_true(void)
{
	TEST_ASSERT_TRUE(ft_strequ(NULL, NULL));
}

void	test_when_s1_null_s2_non_null_then_false(void)
{
	TEST_ASSERT_FALSE(ft_strequ(NULL, "Akd lw"));
}

void	test_when_s1_non_null_s2_null_then_false(void)
{
	TEST_ASSERT_FALSE(ft_strequ("Hello workd", NULL));
}

void	test_when_identical_then_true(void)
{
	TEST_ASSERT_TRUE(ft_strequ("Hello World!\n","Hello World!\n"));
}

void	test_when_different_then_false(void)
{
	TEST_ASSERT_FALSE(ft_strequ("Hello World!\n","Hello world!\n"));
}

void	test_when_s1_shorter_then_s2_then_false(void)
{
	TEST_ASSERT_FALSE(ft_strequ("Hello !\n","Hello World!\n"));
}

void	test_when_s1_longer_than_s2_then_false(void)
{
	TEST_ASSERT_FALSE(ft_strequ("Hello World!\n","Hello !\n"));
}
