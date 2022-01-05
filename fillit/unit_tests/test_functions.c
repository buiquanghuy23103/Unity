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

void	test_bit_arr(void)
{
	const uint16_t			VALID[112] = {
	0b1100100010000000, 0b0110010001000000, 0b0011001000100000,
	0b0000110010001000, 0b0000011001000100, 0b0000001100100010,
	0b1110001000000000, 0b0111000100000000, 0b0000111000100000,
	0b0000011100010000, 0b0000000011100010, 0b0000000001110001,
	0b0100010011000000, 0b0010001001100000, 0b0001000100110000,
	0b0000010001001100, 0b0000001000100110, 0b0000000100010011,
	0b1000111000000000, 0b0100011100000000, 0b0000100011100000,
	0b0000010001110000, 0b0000000010001110, 0b0000000001000111,
	0b1100010001000000, 0b0110001000100000, 0b0011000100010000,
	0b0000110001000100, 0b0000011000100010, 0b0000001100010001,
	0b0010111000000000, 0b0001011100000000, 0b0000001011100000,
	0b0000000101110000, 0b0000000000101110, 0b0000000000010111,
	0b1000100011000000, 0b0100010001100000, 0b0010001000110000,
	0b0000100010001100, 0b0000010001000110, 0b0000001000100011,
	0b1110001000000000, 0b0111000100000000, 0b0000111000100000,
	0b0000011100010000, 0b0000000011100010, 0b0000000001110001,
	0b1100110000000000, 0b0110011000000000, 0b0011001100000000,
	0b0000110011000000, 0b0000011001100000, 0b0000000011001100,
	0b0000000001100110, 0b0000000000110011, 0b1111000000000000,
	0b0000111100000000, 0b0000000011110000, 0b0000000000001111,
	0b1000100010001000, 0b0100010001000100, 0b0010001000100010,
	0b0001000100010001, 0b1000110010000000, 0b0100011001000000,
	0b0010001100100000, 0b0000100011001000, 0b0000010001100100,
	0b0000001000110010, 0b1110010000000000, 0b0111001000000000,
	0b0000111001000000, 0b0000011100100000, 0b0000000011100100,
	0b0000000001110010, 0b0100110001000000, 0b0010011000100000,
	0b0001001100010000, 0b0000010011000100, 0b0000001001100010,
	0b0000000100110001, 0b0100111000000000, 0b0010011100000000,
	0b0000010011100000, 0b0000001001110000, 0b0000000001001110,
	0b0000000000100111, 0b1100011000000000, 0b0110001100000000,
	0b0000110001100000, 0b0000011000110000, 0b0000000011000110,
	0b0000000001100011, 0b0100110010000000, 0b0010011001000000,
	0b0001001100100000, 0b0000010011001000, 0b0000001001100100,
	0b0000000100110010, 0b0110110000000000, 0b0011011000000000,
	0b0000011011000000, 0b0000001101100000, 0b0000000001101100,
	0b0000000000110110, 0b1000110001000000, 0b0100011000100000,
	0b0010001100010000, 0b0000100011000100, 0b0000010001100010,
	0b0000001000110001
};
	int		fd;
	int		i;
	int		k;
	int		diff;
	char	*line;

	fd = open("sandbox/all_tetriminos.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);
	i = 0;
	while (i < 112)
	{
		k = 15;
		while (k >= 0)
		{
			if (ft_getbit(VALID[i], k))
				ft_putchar_fd('#', fd);
			else
				ft_putchar_fd('.', fd);
			if (k % 4 == 0)
				ft_putchar_fd('\n', fd);
			k--;
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
	close(fd);
	system("diff sandbox/all_tetriminos.txt sandbox/all_tetriminos.txt.mine > sandbox/all_tetriminos.diff");
	fd = open("sandbox/all_tetriminos.diff", O_RDONLY);
	diff = read(fd, &line, 10);
	TEST_ASSERT_EQUAL_INT(0, diff);
}

void	test_ft_top_overlap(void)
{
	int	actual[19];
	int	expected[19];

	bzero(actual, sizeof(actual));
	actual[2] = 1;
	actual[3] = 1;
	actual[4] = 1;
	actual[5] = 1;
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
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 19);
}


void	test_move_top_from_bottom(void)
{
	int	actual[19];
	int	expected[19];

	bzero(actual, sizeof(actual));
	actual[12] = 1;
	actual[13] = 1;
	actual[14] = 1;
	actual[15] = 1;
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
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 19);
}

void	test_ft_left(void)
{
	int	actual[19];
	int	expected[19];

	bzero(actual, sizeof(actual));
	actual[3] = 1;
	actual[4] = 1;
	actual[5] = 1;
	actual[6] = 1;
	actual[SIZE] = 6;
	actual[SROW] = 3;
	actual[HEIGHT] = 4;

	bzero(expected, sizeof(expected));
	expected[3] = 32;
	expected[4] = 32;
	expected[5] = 32;
	expected[6] = 32;
	expected[SIZE] = 6;
	expected[SROW] = 3;
	expected[HEIGHT] = 4;

	ft_left(actual);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 19);
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

	a->tmino[1][3] = 0b1111;
	a->tmino[1][SROW] = 3;
	a->tmino[1][HEIGHT] = 1;

	a->tmino[2][1] = 0b1000;
	a->tmino[2][2] = 0b1110;
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
	int	actual[19];
	int	expected[19];
	int	ret;

	bzero(actual, sizeof(actual));
	actual[3] = 0b110;
	actual[4] = 0b011;
	actual[SIZE] = 6;
	actual[SROW] = 3;
	actual[HEIGHT] = 2;

	bzero(expected, sizeof(expected));
	expected[3] = 0b110;
	expected[4] = 0b011;
	expected[SIZE] = 6;
	expected[SROW] = 3;
	expected[HEIGHT] = 2;

	ret = ft_right(actual);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 19);
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, ret, "should return 0 if cannot move right");
}

void	test_ft_right_doable(void)
{
	int	actual[19];
	int	expected[19];
	int	ret;

	bzero(actual, sizeof(actual));
	actual[3] = 0b1100;
	actual[4] = 0b0110;
	actual[SIZE] = 6;
	actual[SROW] = 3;
	actual[HEIGHT] = 2;

	bzero(expected, sizeof(expected));
	expected[3] = 0b110;
	expected[4] = 0b011;
	expected[SIZE] = 6;
	expected[SROW] = 3;
	expected[HEIGHT] = 2;

	ret = ft_right(actual);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 19);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, ret, "should return 1 if moving right succeed");
}

void	test_ft_down_doable(void)
{
	int	actual[19];
	int	expected[19];
	int	ret;

	bzero(actual, sizeof(actual));
	actual[3] = 0b110;
	actual[4] = 0b011;
	actual[SIZE] = 6;
	actual[SROW] = 3;
	actual[HEIGHT] = 2;

	bzero(expected, sizeof(expected));
	expected[4] = 0b110000;
	expected[5] = 0b011000;
	expected[SIZE] = 6;
	expected[SROW] = 4;
	expected[HEIGHT] = 2;

	ret = ft_down(actual);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 19);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, ret, "should return 1 if moving down succeeds");
}

void	test_ft_down_not_doable_2(void)
{
	int	actual[19];
	int	expected[19];
	int	ret;

	bzero(actual, sizeof(actual));
	actual[4] = 0b110;
	actual[5] = 0b011;
	actual[SIZE] = 6;
	actual[SROW] = 4;
	actual[HEIGHT] = 2;

	bzero(expected, sizeof(expected));
	expected[4] = 0b110;
	expected[5] = 0b011;
	expected[SIZE] = 6;
	expected[SROW] = 4;
	expected[HEIGHT] = 2;

	ret = ft_down(actual);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 19);
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, ret, "should return 0 if moving down fails");
}

void	test_ft_down_not_doable_1(void)
{
	int	actual[19];
	int	expected[19];
	int	ret;

	bzero(actual, sizeof(actual));
	actual[14] = 0b110;
	actual[15] = 0b011;
	actual[SIZE] = 16;
	actual[SROW] = 14;
	actual[HEIGHT] = 2;

	bzero(expected, sizeof(expected));
	expected[14] = 0b110;
	expected[15] = 0b011;
	expected[SIZE] = 16;
	expected[SROW] = 14;
	expected[HEIGHT] = 2;

	ret = ft_down(actual);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 19);
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, ret, "should return 0 if moving down fails");
}
