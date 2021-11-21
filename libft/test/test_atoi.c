#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}
void	test_when_only_space(void)
{
	const char *str = " \t";
	TEST_ASSERT_EQUAL(atoi(str), ft_atoi(str)); 
}
void	test_when_negative(void)
{
	const char *str = "-749";
	TEST_ASSERT_EQUAL(atoi(str), ft_atoi(str)); 
}
void	test_when_positive(void)
{
	const char *str = "749";
	TEST_ASSERT_EQUAL(atoi(str), ft_atoi(str)); 
}
void	test_when_non_number_behind(void)
{
	const char *str = "749a3";
	TEST_ASSERT_EQUAL(atoi(str), ft_atoi(str)); 
}
void	test_when_non_number_before(void)
{
	const char *str = "a7493";
	TEST_ASSERT_EQUAL(atoi(str), ft_atoi(str)); 
}
void	test_when_two_minus_symbol(void)
{
	const char *str = "--7493";
	TEST_ASSERT_EQUAL(atoi(str), ft_atoi(str)); 
}
void	test_when_one_plus_symbol(void)
{
	const char *str = "+7493";
	TEST_ASSERT_EQUAL(atoi(str), ft_atoi(str)); 
}
void	test_when_space_before(void)
{
	const char *str = " 7493";
	TEST_ASSERT_EQUAL(atoi(str), ft_atoi(str)); 
}
void	test_when_symbol_space_before(void)
{
	const char *str = "+ 7493";
	TEST_ASSERT_EQUAL(atoi(str), ft_atoi(str)); 
}
void	test_when_space_symbol_before(void)
{
	const char *str = " +7493";
	TEST_ASSERT_EQUAL(atoi(str), ft_atoi(str)); 
}
