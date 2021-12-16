#include "get_next_line.h"
#include "unity.h"
#include "testft.h"
#include <string.h>
#include <stdlib.h>

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_medium_string_no_nl(void)
{
	char 	*line;
	int		out;
	int		p[2];
	char 	*str;
	int		gnl_ret;

	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	write(1, str, strlen(str));
	close(p[1]);
	dup2(out, 1);

	gnl_ret = get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING(str, line);
	ft_strdel(&str);
	ft_strdel(&line);
	TEST_ASSERT_UINT_WITHIN(1, 0, gnl_ret);
}

void	test_simple_string(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	fd = 1;
	out = dup(fd);
	pipe(p);

	dup2(p[1], fd);
	write(fd, "aaa\nbbb\nccc\nddd\n", 16);
	dup2(out, fd);
	close(p[1]);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("aaa", line);
	ft_strdel(&line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("bbb", line);
	ft_strdel(&line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("ccc", line);
	ft_strdel(&line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("ddd", line);
	ft_strdel(&line);
}

void	test_eof_with_close(void)
{
	char *line;
	int		out;
	int		p[2];
	int		fd;
	int		gnl_ret;

	fd = 1;
	out = dup(fd);
	pipe(p);
	dup2(p[1], fd);
	write(fd, "aaa", 3);
	close(p[1]);
	dup2(out, fd);

	gnl_ret = get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("aaa", line);
	ft_strdel(&line);
	TEST_ASSERT_UINT_WITHIN(1, 0, gnl_ret);
}

void	test_return_values(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		gnl_ret;

	out = dup(1);
	pipe(p);
	fd = 1;
	dup2(p[1], fd);
	write(fd, "abc\n\n", 5);
	close(p[1]);
	dup2(out, fd);

	/* Read abc and new line */
	gnl_ret = get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("abc", line);
	ft_strdel(&line);
	TEST_ASSERT_EQUAL_INT(1, gnl_ret);

	/* Read new line */
	gnl_ret = get_next_line(p[0], &line);
	TEST_ASSERT_EMPTY(line);
	ft_strdel(&line);
	TEST_ASSERT_EQUAL_INT(1, gnl_ret);

	/* Read again, but meet EOF */
	gnl_ret = get_next_line(p[0], &line);
	TEST_ASSERT_EMPTY(line);
	ft_strdel(&line);
	TEST_ASSERT_EQUAL_INT(0, gnl_ret);

	/* Let's do it once again */
	gnl_ret = get_next_line(p[0], &line);
	TEST_ASSERT_EMPTY(line);
	ft_strdel(&line);
	TEST_ASSERT_EQUAL_INT(0, gnl_ret);
}

void	test_when_fd_negative(void)
{
	char	*line = NULL;
	TEST_ASSERT_EQUAL_INT(-1, get_next_line(-99, &line));
	TEST_ASSERT_EQUAL_INT(-1, get_next_line(-1, &line));
	TEST_ASSERT_EQUAL_INT(-1, get_next_line(-10000, &line));
}

void	test_when_file_not_exist(void)
{
	char	*line = NULL;

	TEST_ASSERT_EQUAL_INT(-1, get_next_line(42, &line));
}

void	test_when_line_null(void)
{
	int fd = open("makefile", O_RDONLY);

	TEST_ASSERT_EQUAL_INT(-1, get_next_line(fd, NULL));
}

void	test_line_of_08_with_nl(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "oiuytrew\n", 9);
	close(p[1]);
	dup2(out, fd);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("oiuytrew", line);
	ft_strdel(&line);
}

void	test_two_lines_of_08(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	
	out = dup(1);
	pipe(p);
	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefgh\n", 9);
	write(fd, "ijklmnop\n", 9);
	close(p[1]);
	dup2(out, fd);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("abcdefgh", line);
	ft_strdel(&line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("ijklmnop", line);
	ft_strdel(&line);
}

void	test_one_line_of_16_no_nl(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		ret;

	out = dup(1);
	pipe(p);
	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefghijklmnop\n", 17);
	close(p[1]);
	dup2(out, fd);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("abcdefghijklmnop", line);
	ft_strdel(&line);

	ret = get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_INT(0, ret);
}

void	test_two_lines_of_16(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefghijklmnop\n", 17);
	write(fd, "qrstuvwxyzabcdef\n", 17);
	close(p[1]);
	dup2(out, fd);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("abcdefghijklmnop", line);
	ft_strdel(&line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("qrstuvwxyzabcdef", line);
	ft_strdel(&line);

	ret = get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_INT(0, ret);
}

void	test_few_lines_of_16(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefghijklmnop\n", 17);
	write(fd, "qrstuvwxyzabcdef\n", 17);
	write(fd, "ghijklmnopqrstuv\n", 17);
	write(fd, "wxyzabcdefghijkl\n", 17);
	write(fd, "mnopqrstuvwxyzab\n", 17);
	write(fd, "cdefghijklmnopqr\n", 17);
	write(fd, "stuvwxzabcdefghi\n", 17);
	close(p[1]);
	dup2(out, fd);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("abcdefghijklmnop", line);
	ft_strdel(&line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("qrstuvwxyzabcdef", line);
	ft_strdel(&line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("ghijklmnopqrstuv", line);
	ft_strdel(&line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("wxyzabcdefghijkl", line);
	ft_strdel(&line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("mnopqrstuvwxyzab", line);
	ft_strdel(&line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("cdefghijklmnopqr", line);
	ft_strdel(&line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("stuvwxzabcdefghi", line);
	ft_strdel(&line);

	ret = get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_INT(0, ret);
}

void	test_line_of_4(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		ret;

	out = dup(1);
	pipe(p);
	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcd\n", 5);
	close(p[1]);
	dup2(out, fd);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("abcd", line);
	ft_strdel(&line);
	ret = get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_INT(0, ret);
}

void	test_two_lines_of_4(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		ret;

	out = dup(1);
	pipe(p);
	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcd\n", 5);
	write(fd, "efgh\n", 5);
	close(p[1]);
	dup2(out, fd);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("abcd", line);
	ft_strdel(&line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("efgh", line);
	ft_strdel(&line);

	ret = get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_INT(0, ret);
}

void	test_few_lines_of_4(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcd\n", 5);
	write(fd, "efgh\n", 5);
	write(fd, "ijkl\n", 5);
	write(fd, "mnop\n", 5);
	write(fd, "qrst\n", 5);
	write(fd, "uvwx\n", 5);
	write(fd, "yzab\n", 5);
	close(p[1]);
	dup2(out, fd);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("abcd", line);
	ft_strdel(&line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("efgh", line);
	ft_strdel(&line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("ijkl", line);
	ft_strdel(&line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("mnop", line);
	ft_strdel(&line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("qrst", line);
	ft_strdel(&line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("uvwx", line);
	ft_strdel(&line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("yzab", line);
	ft_strdel(&line);

	ret = get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_INT(0, ret);
}

void	test_line_no_nl(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcd", 4);
	close(p[1]);
	dup2(out, fd);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("abcd", line);
	ft_strdel(&line);
}

void	test_line_of_8_no_nl(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "efghijkl", 8);
	close(p[1]);
	dup2(out, fd);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("efghijkl", line);
	ft_strdel(&line);
}

void	test_line_of_16_no_nl(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "mnopqrstuvwxyzab", 16);
	close(p[1]);
	dup2(out, fd);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("mnopqrstuvwxyzab", line);
	ft_strdel(&line);
}
