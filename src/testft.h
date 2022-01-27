#ifndef TESTFT_H
# define TESTFT_H

# include "unity.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <ctype.h>
# include <unistd.h>

void	init_redirect(int *file_desc, int *copy_out);
void	reset_output(int *copy_out);
void	clean_up(FILE * file);
int		open_temp();
char	*read_file(int fd);
void	TEST_ASSERT_FILE_CONTENT(char *expected,
			int filedesc);

#endif
