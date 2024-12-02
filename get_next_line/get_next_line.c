/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:44:12 by kadachi           #+#    #+#             */
/*   Updated: 2024/12/01 12:25:33 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*putc_and_dump(char *str, char c)
{
	static char		buf[BUFFER_SIZE + 1];
	static ssize_t	pos;
	char			*tmp;

	if (c != EOF)
		buf[pos++] = c;
	if (pos == BUFFER_SIZE || c == '\n' || c == EOF)
	{
		buf[pos] = '\0';
		tmp = ft_strjoin(str, buf);
		free(str);
		pos = 0;
		if (tmp == NULL)
			return (NULL);
		str = tmp;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char	c;
	char	*line;

	line = ft_strjoin("", "");
	while (1)
	{
		c = ft_fgetc(fd);
		line = putc_and_dump(line, c);
		if (line == NULL)
			return (NULL);
		if (c == '\n' || c == EOF)
			break ;
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// int main(void)
// {
// 	char *line;
// 	line = get_next_line(STDIN_FILENO);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(STDIN_FILENO);
// 	}
// 	return (0);
// }
