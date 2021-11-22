#ifndef TESTFT_H
# define TESTFT_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <ctype.h>
# include "libft.h"

void	init_redirect(int *file_desc, int *copy_out);
void	reset_output(int *copy_out);
void	clean_up(FILE * file);
size_t	file_size(FILE *file);
char	*actual_stdout_str(int fd);

#endif
