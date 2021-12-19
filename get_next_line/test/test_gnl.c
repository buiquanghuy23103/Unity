#include "get_next_line.h"
#include "unity.h"
#include "testft.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

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
	if (line)
		TEST_ASSERT_EMPTY(line);
	ft_strdel(&line);
	TEST_ASSERT_EQUAL_INT(1, gnl_ret);

	/* Read again, but meet EOF */
	gnl_ret = get_next_line(p[0], &line);
	if (line)
		TEST_ASSERT_EMPTY(line);
	ft_strdel(&line);
	TEST_ASSERT_EQUAL_INT(0, gnl_ret);

	/* Let's do it once again */
	gnl_ret = get_next_line(p[0], &line);
	if (line)
		TEST_ASSERT_EMPTY(line);
	ft_strdel(&line);
	TEST_ASSERT_EQUAL_INT(0, gnl_ret);
}

void	test_return_values_when_line_equal_buff_size_and_no_newline(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		gnl_ret;
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	i = 0;
	str[BUFF_SIZE] = '\0';
	while (i < BUFF_SIZE)
	{
		str[i] = ' ' + i % 93;
		i++;
	}
	out = dup(1);
	pipe(p);
	fd = 1;
	dup2(p[1], fd);
	write(fd, str, BUFF_SIZE);
	close(p[1]);
	dup2(out, fd);

	gnl_ret = get_next_line(p[0], &line);
	TEST_ASSERT_EQUAL_STRING(str, line);
	ft_strdel(&line);
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, gnl_ret, "Your function should return 1 after reading the last line");

	/* Read again, but meet EOF */
	gnl_ret = get_next_line(p[0], &line);
	if (line)
		TEST_ASSERT_EMPTY(line);
	ft_strdel(&line);
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, gnl_ret, "Your function should return 0 when there is nothing to read");

	/* Let's do it once again */
	gnl_ret = get_next_line(p[0], &line);
	if (line)
		TEST_ASSERT_EMPTY(line);
	ft_strdel(&line);
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, gnl_ret, "Your function should continue returning 0, when EOF is met");
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

void	test_multiple_fd(void)
{
	char	*line_fd0;
	int		p_fd0[2];
	int		fd0 = 0;
	int		out_fd0 = dup(fd0);

	char	*line_fd1;
	int		p_fd1[2];
	int		fd1 = 1;
	int		out_fd1 = dup(fd1);

	char	*line_fd2;
	int		p_fd2[2];
	int		fd2 = 2;
	int		out_fd2 = dup(fd2);

	char	*line_fd3;
	int		p_fd3[2];
	int		fd3 = 3;
	int		out_fd3 = dup(fd3);

	pipe(p_fd0);
	dup2(p_fd0[1], fd0);
	write(fd0, "aaa\nbbb\n", 8);
	dup2(out_fd0, fd0);
	close(p_fd0[1]);

	pipe(p_fd1);
	dup2(p_fd1[1], fd1);
	write(fd1, "111\n222\n", 8);
	dup2(out_fd1, fd1);
	close(p_fd1[1]);

	pipe(p_fd2);
	dup2(p_fd2[1], fd2);
	write(fd2, "www\nzzz\n", 8);
	dup2(out_fd2, fd2);
	close(p_fd2[1]);

	pipe(p_fd3);
	dup2(p_fd3[1], fd3);
	write(fd3, "888\n999\n", 8);
	dup2(out_fd3, fd3);
	close(p_fd3[1]);

	get_next_line(p_fd0[0], &line_fd0);
	TEST_ASSERT_EQUAL_STRING("aaa", line_fd0);
	ft_strdel(&line_fd0);

	get_next_line(p_fd1[0], &line_fd1);
	TEST_ASSERT_EQUAL_STRING("111", line_fd1);
	ft_strdel(&line_fd1);

	get_next_line(p_fd2[0], &line_fd2);
	TEST_ASSERT_EQUAL_STRING("www", line_fd2);
	ft_strdel(&line_fd2);

	get_next_line(p_fd3[0], &line_fd3);
	TEST_ASSERT_EQUAL_STRING("888", line_fd3);
	ft_strdel(&line_fd3);

	get_next_line(p_fd0[0], &line_fd0);
	TEST_ASSERT_EQUAL_STRING("bbb", line_fd0);
	ft_strdel(&line_fd0);

	get_next_line(p_fd1[0], &line_fd1);
	TEST_ASSERT_EQUAL_STRING("222", line_fd1);
	ft_strdel(&line_fd1);

	get_next_line(p_fd2[0], &line_fd2);
	TEST_ASSERT_EQUAL_STRING("zzz", line_fd2);
	ft_strdel(&line_fd2);

	get_next_line(p_fd3[0], &line_fd3);
	TEST_ASSERT_EQUAL_STRING("999", line_fd3);
	ft_strdel(&line_fd3);
}

void	test_hard_medium_string(void)
{
	char 	*line;
	int		out;
	int		p[2];
	char 	*str;
	int		len = 50;
	clock_t	t;

	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	while (len--)
		strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	if (str)
		write(1, str, strlen(str));
	close(p[1]);
	dup2(out, 1);

	t = clock();
	get_next_line(p[0], &line);
	t = clock() - t;

	TEST_ASSERT_EQUAL_STRING(str, line);
	ft_strdel(&str);
	ft_strdel(&line);

	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("\033[0;32m%s\033[0m took \033[0;32m%f\033[0m seconds to execute \n", __func__, time_taken);
}

void	test_large_file(void)
{
	char *line;
	int fd;
	int fd2;
	int fd3;
	int	diff_file_size;
	clock_t	t;
    
	fd = open("sandbox/large_file.txt", O_RDONLY);
	fd2 = open("sandbox/large_file.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

	t = clock();
	while (get_next_line(fd, &line) == 1)
	{
	    write(fd2, line, strlen(line));
		ft_strdel(&line);
	    write(fd2, "\n", 1);
	}
	t = clock() - t;
	ft_strdel(&line);

	close(fd);
	close(fd2);

	system("diff sandbox/large_file.txt sandbox/large_file.txt.mine > sandbox/large_file.diff");
	fd3 = open("sandbox/large_file.diff", O_RDONLY);
	line = ""; // prevent "read(buf) points to unaddressable byte(s)" of valgrind"
	diff_file_size = read(fd3, line, 10);
	close(fd3);

	TEST_ASSERT_EQUAL_INT(0, diff_file_size);

	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("\033[0;32m%s\033[0m took \033[0;32m%f\033[0m seconds to execute \n", __func__, time_taken);
}

void	test_one_big_fat_line(void)
{
	char *line;
	int fd;
	int fd2;
	int fd3;
	int	diff_file_size;
	clock_t t;
    
	fd = open("sandbox/one_big_fat_line.txt", O_RDONLY);
	fd2 = open("sandbox/one_big_fat_line.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

	t = clock();
	while (get_next_line(fd, &line) == 1)
	{
	    write(fd2, line, strlen(line));
		ft_strdel(&line);
	    write(fd2, "\n", 1);
	}
	t = clock() - t;
	if (line)
	{
		write(fd2, line, strlen(line));
		ft_strdel(&line);
	}
	close(fd);
	close(fd2);

	system("diff sandbox/one_big_fat_line.txt sandbox/one_big_fat_line.txt.mine > sandbox/one_big_fat_line.diff");
	fd3 = open("sandbox/one_big_fat_line.diff", O_RDONLY);
	line = ""; // prevent "read(buf) points to unaddressable byte(s)" of valgrind"
	diff_file_size = read(fd3, line, 10);
	close(fd3);

	TEST_ASSERT_EQUAL_INT(0, diff_file_size);

	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("\033[0;32m%s\033[0m took \033[0;32m%f\033[0m seconds to execute \n", __func__, time_taken);
}
