/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnishimu <rnishimu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:11:00 by rnishimu          #+#    #+#             */
/*   Updated: 2021/08/10 16:38:55 by rnishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	while (n > 0)
	{
		*a = *b;
		a++;
		b++;
		n--;
	}
	return (dest);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*dest;
	size_t			i;

	if (src == dst || n == 0)
		return (dst);
	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	i = 0;
	if (dest < source)
		ft_memcpy(dest, source, n);
	else
	{
		while (i < n)
		{
			dest[n - 1 - i] = source[n - 1 - i];
			i++;
		}
	}
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{	
	unsigned char	*a;

	a = (unsigned char *)s;
	while (n > 0)
	{
		*a = '\0';
		n--;
		a++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;

	pointer = (void *)malloc(nmemb * size);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, nmemb * size);
	return (pointer);
}
