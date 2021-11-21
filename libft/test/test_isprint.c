#include "libft.h"
#include "unity.h"
#include "ctype.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}
void	test_when_space_then_true(void)
{
	TEST_ASSERT_EQUAL(isprint(' '), ft_isprint(' '));
}
void	test_when_tilde_then_true(void)
{
	TEST_ASSERT_EQUAL(isprint('~'), ft_isprint('~'));
}
void	test_when_tab_then_false(void)
{
	TEST_ASSERT_EQUAL(isprint('\t'), ft_isprint('\t'));
}
void	test_when_new_line_then_false(void)
{
	TEST_ASSERT_EQUAL(isprint('\n'), ft_isprint('\n'));
}
void	test_when_127_then_false(void)
{
	TEST_ASSERT_EQUAL(isprint(127), ft_isprint(127));
}
void	test_when_31_then_false(void)
{
	TEST_ASSERT_EQUAL(isprint(31), ft_isprint(31));
}
