/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimu <rnishimu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:40:10 by rnishimu          #+#    #+#             */
/*   Updated: 2021/08/10 09:40:44 by rnishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*find certain char in a string
*/
static char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != (unsigned char)c)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return ((char *)s);
}

/*function to make new string joining line and buffer
*if '\n' is found, stop and return line at '\n' else join until end of buffer
*/
char	*join(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	new = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (new == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\n' && s2[j] != '\0')
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	if (s2[j] == '\n')
		new[i] = '\n';
	free(s1);
	s1 = new;
	return (new);
}

/*function to cut line at '\n'. 
*save what is left after the '\n' to static buffer.
*set rest of buffer to 0 in case not all is used.
*return everything before and including '\n' as line.
*/
char	*cut_newline(char *line, char *buffer)
{
	char	*ptr;
	int		len;

	len = 0;
	line = join(line, buffer);
	ptr = ft_strchr(buffer, '\n');
	while (ptr[len])
		len++;
	ptr++;
	buffer = ft_memmove(buffer, ptr, len);
	ft_bzero(buffer + len, BUFFER_SIZE - len);
	return (line);
}

/*if read fails and nothing in line. Free line and return false.
*/
int	read_fail(int r_size, char *line)
{
	if (r_size < 1 && (*line == 0))
	{
		free(line);
		return (0);
	}
	return (1);
}

/*
 *Check if fd error.
 *calloc char pointer.
 *while no '\n', if there is something in buffer, join buffer with line.
 *read into buffer BUFFER_SIZE amount and null terminate buffer.
 *check if able to read.
 *if r_size < BUFFER_SIZE and no '\n' is found->
 *join line and buffer, set buffer to 0, Return line.
 *Otherwise keep reading BUFFER_SIZE amounts in while loop until '\n' is found. 
 *When '\n' is found, cut at '\n' store everything after split in buffer.
 *Return line.
*/

char	*get_next_line(int fd)
{
	int			r_size;
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0)
		return (NULL);
	line = (char *)ft_calloc(1, sizeof(char *));
	while (!(ft_strchr(buffer, '\n')))
	{
		line = join(line, buffer);
		r_size = read(fd, buffer, BUFFER_SIZE);
		buffer[r_size] = '\0';
		if (read_fail(r_size, line) == 0)
			return (NULL);
		if (r_size < BUFFER_SIZE && !ft_strchr(buffer, '\n'))
		{
			line = join(line, buffer);
			ft_bzero(buffer, BUFFER_SIZE);
			return (line);
		}
	}
	line = cut_newline(line, buffer);
	return (line);
}
