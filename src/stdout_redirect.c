/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:22:45 by cchen             #+#    #+#             */
/*   Updated: 2022/01/27 08:09:59 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	open_temp()
{
	int	fd;

	fd = open("temp", O_RDWR|O_CREAT|O_TRUNC, 0666);
	if (fd == -1)
	{
		fprintf(stderr, "Could not open temp file.\n");
		exit (1);
	}
	return (fd);
}

void	init_redirect(int *file_desc, int *copy_out)
{
	*file_desc = open_temp();
	*copy_out = dup(fileno(stdout));
	dup2(*file_desc, fileno(stdout));
}

void	reset_output(int *copy_out)
{
	dup2(*copy_out, fileno(stdout));
	close(*copy_out);
}

void	clean_up(FILE * file)
{
	if (fclose(file))
	{
		fprintf(stderr, "Cannot close temp file\n");
		exit (1);
	}
	if (remove("temp"))
	{
		fprintf(stderr, "Cannot remove temp file\n");
		exit (1);
	}
}

static size_t	file_size(FILE *file)
{
	long	size;

	fseek(file, 0L, SEEK_END);
	size = ftell(file);
	rewind(file);
	if (size >= 0)
		return ((size_t) size);
	else
		return (0);
}

char	*read_file(int fd)
{
	FILE	*file;
	size_t	size;
	char	*actual;
	int		error;

	file = fdopen(fd, "r");
	size = file_size(file);
	rewind(file);
	actual = (char*)malloc(sizeof(char) * (size + 1));
	if (!actual)
		return (NULL);
	fread(actual, sizeof(char), size, file);
	actual[size] = '\0';
	if ((error = ferror(file)) != 0)
	{
		fprintf(stderr, "Cannot read temp file\n. Error code: %d", error);
		clean_up(file);
		exit(1);
	}
	clean_up(file);
	return (actual);
}

void	TEST_ASSERT_FILE_CONTENT(char *expected, int file_desc)
{
	char	*actual;

	actual = read_file(file_desc);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
}
