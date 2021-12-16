#include "get_next_line.h"
#include "unity.h"
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

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("bbb", line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("ccc", line);

	get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING("ddd", line);
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
	TEST_ASSERT_UINT_WITHIN(1, 0, gnl_ret);
}
