/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-22 16:06:48 by mjaad             #+#    #+#             */
/*   Updated: 2025-12-22 16:06:48 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*location;
	char	*origin;
	size_t	len;

	len = ft_strlen(s);
	location = (char *)malloc(len + 1);
	if (!location)
		return (location);
	origin = location;
	while (*s)
		*location++ = *s++;
	*location = '\0';
	return (origin);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*location;
	char	*origin;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	location = (char *)malloc(len + 1);
	if (!(location) || !(s))
		return (NULL);
	s += start;
	origin = location;
	while (len--)
		*location++ = *s++;
	*location = '\0';
	return (origin);
}
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size && nmemb > ((size_t)-1) / size)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_p;
	unsigned char	*src_p;

	dest_p = (unsigned char *)dest;
	src_p = (unsigned char *)src;
	while (n--)
		*dest_p++ = *src_p++;
	return (dest);
}