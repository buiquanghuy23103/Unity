#include "libft.h"
#include "testft.h"
#include "fillit.h"
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

void	test_ft_top_overlap(void)
{
	int	actual[T_SIZE];
	int	expected[T_SIZE];

	bzero(actual, sizeof(actual));
	actual[0] = 1;
	actual[1] = 1;
	actual[2] = 1;
	actual[3] = 1;
	actual[SIZE] = 6;
	actual[SROW] = 2;
	actual[HEIGHT] = 4;

	bzero(expected, sizeof(expected));
	expected[0] = 1;
	expected[1] = 1;
	expected[2] = 1;
	expected[3] = 1;
	expected[SIZE] = 6;
	expected[SROW] = 0;
	expected[HEIGHT] = 4;

	ft_top(actual);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, T_SIZE);
}


void	test_move_top_from_bottom(void)
{
	int	actual[T_SIZE];
	int	expected[T_SIZE];

	bzero(actual, sizeof(actual));
	actual[0] = 1;
	actual[1] = 1;
	actual[2] = 1;
	actual[3] = 1;
	actual[SIZE] = 6;
	actual[SROW] = 12;
	actual[HEIGHT] = 4;

	bzero(expected, sizeof(expected));
	expected[0] = 1;
	expected[1] = 1;
	expected[2] = 1;
	expected[3] = 1;
	expected[SIZE] = 6;
	expected[SROW] = 0;
	expected[HEIGHT] = 4;

	ft_top(actual);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, T_SIZE);
}

void	test_ft_left(void)
{
	int	actual[T_SIZE];
	int	expected[T_SIZE];

	bzero(actual, sizeof(actual));
	actual[0] = 1;
	actual[1] = 1;
	actual[2] = 1;
	actual[3] = 1;
	actual[SIZE] = 6;
	actual[SROW] = 3;
	actual[HEIGHT] = 4;

	bzero(expected, sizeof(expected));
	expected[0] = 32;
	expected[1] = 32;
	expected[2] = 32;
	expected[3] = 32;
	expected[SIZE] = 6;
	expected[SROW] = 3;
	expected[HEIGHT] = 4;

	ft_left(actual);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, T_SIZE);
}

void	test_ft_left_2(void)
{
	int	actual[T_SIZE];
	int	expected[T_SIZE];

	bzero(actual, sizeof(actual));
	actual[0] = 0b001;
	actual[1] = 0b111;
	actual[2] = 0;
	actual[3] = 0;
	actual[SIZE] = 3;
	actual[SROW] = 3;
	actual[HEIGHT] = 2;

	bzero(expected, sizeof(expected));
	expected[0] = 0b001;
	expected[1] = 0b111;
	expected[2] = 0;
	expected[3] = 0;
	expected[SIZE] = 3;
	expected[SROW] = 3;
	expected[HEIGHT] = 2;

	ft_left(actual);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, T_SIZE);
}
void	test_ft_print_tetrimino(void)
{
	const int	size = 4;
	t_tetr		a[1];
	int			fd;
	int			copy_out;
	char		*expected;

	ft_inil_tetr(a, size);

	expected = "DDAA\nCDDA\nCCCA\nBBBB\n";

	a->tmino[0][0] = 0b0011;
	a->tmino[0][1] = 0b0001;
	a->tmino[0][2] = 0b0001;
	a->tmino[0][SROW] = 0;
	a->tmino[0][HEIGHT] = 3;

	a->tmino[1][0] = 0b1111;
	a->tmino[1][SROW] = 3;
	a->tmino[1][HEIGHT] = 1;

	a->tmino[2][0] = 0b1000;
	a->tmino[2][1] = 0b1110;
	a->tmino[2][SROW] = 1;
	a->tmino[2][HEIGHT] = 2;

	a->tmino[3][0] = 0b1100;
	a->tmino[3][1] = 0b0110;
	a->tmino[3][SROW] = 0;
	a->tmino[3][HEIGHT] = 2;

	a->tcount = 4;

	init_redirect(&fd, &copy_out);
	ft_print_tetriminos(a, a->tcount);
	reset_output(&copy_out);

	TEST_ASSERT_FILE_CONTENT(expected, fd);
}

void	test_ft_right_not_doable(void)
{
	int	actual[T_SIZE];
	int	expected[T_SIZE];
	int	ret;

	bzero(actual, sizeof(actual));
	actual[0] = 0b110;
	actual[1] = 0b011;
	actual[SIZE] = 3;
	actual[WIDTH] = 3;
	actual[SROW] = 0;
	actual[HEIGHT] = 2;
	actual[SCOL] = 0;

	memcpy(expected, actual, sizeof(actual));

	ret = ft_right(actual);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, T_SIZE);
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, ret, "should return 0 if cannot move right");
}

void	test_ft_right_doable(void)
{
	int	actual[T_SIZE];
	int	expected[T_SIZE];
	int	ret;

	bzero(actual, sizeof(actual));
	actual[0] = 0b1100;
	actual[1] = 0b0110;
	actual[SIZE] = 4;
	actual[SROW] = 3;
	actual[HEIGHT] = 2;
	actual[WIDTH] = 3;
	actual[SCOL] = 0;

	memcpy(expected, actual, sizeof(actual));
	expected[SCOL] = 1;

	ret = ft_right(actual);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, T_SIZE);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, ret, "should return 1 if moving right succeed");
}

//void	test_ft_down_doable(void)
//{
//	int	actual[T_SIZE];
//	int	expected[T_SIZE];
//	int	ret;
//
//	bzero(actual, sizeof(actual));
//	actual[0] = 0b1100;
//	actual[1] = 0b0110;
//	actual[SIZE] = 4;
//	actual[SROW] = 0;
//	actual[HEIGHT] = 2;
//	actual[WIDTH] = 3;
//	actual[SCOL] = 1;
//
//	memcpy(expected, actual, sizeof(actual));
//	expected[SROW] = 1;
//	expected[SCOL] = 0;
//
//	ret = ft_down(actual);
//	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, T_SIZE);
//	TEST_ASSERT_EQUAL_INT_MESSAGE(1, ret, "should return 1 if moving down succeeds");
//}
//
//void	test_ft_down_not_doable_2(void)
//{
//	int	actual[T_SIZE];
//	int	expected[T_SIZE];
//	int	ret;
//
//	bzero(actual, sizeof(actual));
//	actual[0] = 0b110;
//	actual[1] = 0b011;
//	actual[SIZE] = 6;
//	actual[SROW] = 4;
//	actual[HEIGHT] = 2;
//
//	bzero(expected, sizeof(expected));
//	expected[0] = 0b110;
//	expected[1] = 0b011;
//	expected[SIZE] = 6;
//	expected[SROW] = 4;
//	expected[HEIGHT] = 2;
//
//	ret = ft_down(actual);
//	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, T_SIZE);
//	TEST_ASSERT_EQUAL_INT_MESSAGE(0, ret, "should return 0 if moving down fails");
//}
//
//void	test_ft_down_not_doable_1(void)
//{
//	int	actual[T_SIZE];
//	int	expected[T_SIZE];
//	int	ret;
//
//	bzero(actual, sizeof(actual));
//	actual[0] = 0b110;
//	actual[1] = 0b011;
//	actual[SIZE] = 16;
//	actual[SROW] = 14;
//	actual[HEIGHT] = 2;
//
//	bzero(expected, sizeof(expected));
//	expected[0] = 0b110;
//	expected[1] = 0b011;
//	expected[SIZE] = 16;
//	expected[SROW] = 14;
//	expected[HEIGHT] = 2;
//
//	ret = ft_down(actual);
//	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, T_SIZE);
//	TEST_ASSERT_EQUAL_INT_MESSAGE(0, ret, "should return 0 if moving down fails");
//}

void	test_place_tetrimino(void)
{
	int	tetr[T_SIZE];
	int	expected[16];
	int	actual[16];

	bzero(tetr, sizeof(tetr));
	tetr[0] = 0b1100;
	tetr[1] = 0b0110;
	tetr[SIZE] = 4;
	tetr[SROW] = 2;
	tetr[HEIGHT] = 2;
	tetr[WIDTH] = 2;
	tetr[SCOL] = 1;

	bzero(expected, sizeof(expected));
	bzero(actual, sizeof(actual));

	expected[2] = 0b0110;
	expected[3] = 0b0011;

	ft_place_piece(actual + tetr[SROW], tetr);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 16);
}

void	test_remove_tetrimino(void)
{
	int			actual[16];
	int			expected[16];
	int			tetr[T_SIZE];

	bzero(actual, sizeof(actual));
	bzero(expected, sizeof(expected));

	bzero(tetr, sizeof(tetr));
	tetr[0] = 0b1100;
	tetr[1] = 0b0110;
	tetr[SIZE] = 4;
	tetr[SROW] = 2;
	tetr[HEIGHT] = 2;
	tetr[WIDTH] = 2;
	tetr[SCOL] = 1;

	ft_place_piece(actual, tetr);

	ft_remove_piece(actual, tetr);

	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 16);
}

void	test_check_fit(void)
{
	int	tetr[T_SIZE];
	int	solution[16];

	bzero(tetr, sizeof(tetr));
	tetr[0] = 0b110;
	tetr[1] = 0b011;
	tetr[SIZE] = 16;
	tetr[SROW] = 14;
	tetr[HEIGHT] = 2;

	bzero(solution, sizeof(solution));
	solution[13] = 0b011;
	solution[14] = 0b011;

	TEST_ASSERT_EQUAL_INT(0, ft_check_fit(solution, tetr));
}

void	test_check_fit_2(void)
{
	int	tetr[T_SIZE];
	int	solution[16];

	bzero(tetr, sizeof(tetr));
	tetr[0] = 0b110;
	tetr[1] = 0b011;
	tetr[SIZE] = 16;
	tetr[SROW] = 14;
	tetr[HEIGHT] = 2;

	bzero(solution, sizeof(solution));
	solution[13] = 0b111;
	solution[14] = 0b001;

	TEST_ASSERT_EQUAL_INT(1, ft_check_fit(solution, tetr));
}

void	test_set_storage(void)
{
	int		size;
	t_tetr	actual[1];
	int		expect[]= {	0b1110,
						0b0010,
						0b0000,
						0b0000};
	int		input[] = {	0, 0, 0, 0,
						0, 1, 1, 1,
						0, 0, 0, 1,
						0, 0, 0, 0};

	size = 4;

	actual->tcount = 0;
	ft_inil_tetr(actual, size);
	ft_set_storage(actual, input);

	TEST_ASSERT_EQUAL_INT_ARRAY(expect, actual->tmino[0], sizeof(int) * 3);
}
