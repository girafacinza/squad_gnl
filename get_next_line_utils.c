/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:20:10 by maraujo-          #+#    #+#             */
/*   Updated: 2020/05/10 20:00:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			ft_bzero(void *b, size_t len)
{
	unsigned char		*str;
	unsigned long int	i;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*str = 0;
		i++;
		str++;
	}
}

int				ft_strlen(const char *s)
{
	unsigned long i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t len;

	if (!src)
		return (0);
	len = 0;
	while (len + 1 < dstsize && *(src + len))
	{
		*(dst + len) = *(src + len);
		len++;
	}
	if (dstsize != 0)
		*(dst + len) = '\0';
	while (*(src + len))
		len++;
	return (len);
}
/*
static	void	**ft_malloc_line(char *temp)
{
	size_t	n_chars;
	void	*mem;

	n_chars = 0;
	while (*temp != '\n')
		n_chars++;
	if (!(mem = malloc(sizeof(char*) * (n_chars + 1))))
		return (NULL);
	return (mem);
}

static	int		ft_get_status(char *temp, char **line)
{
	int	status;
	int	i;

	status = 1;
	i = 0;
	while (*temp != '\n')
	{
		line[i]
	}
}

char			*ft_strdup(char *s1, int init, int final)
{
	char	*s1_cpy;
	int	len;
	int	i;

	i = 0;
	len = ft_strlen((char *)s1);
	if (!(s1_cpy = (char *)malloc((len - init + 1) * sizeof(char))))
		return (NULL);
	while (i + init < len && len < final)
	{
		*(s1_cpy + i) = *(s1 + init + i);
		i++;
	}
	*(s1_cpy + i) = '\0';
	return (s1_cpy);
}

char			*ft_substr(const char *s, int start, int len)
{
	char	*str;
	int	i;
	int	s_len;

	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	while ((i < len) && (start + i) < s_len)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char			*ft_strjoin(char *str1, char *str2)
{
	char	*str;
	int	len;
	int	i;

	i = 0;
	if (!str1)
	{
		str = ft_strdup(str2, 0);
		return (str);
	}
	len = ft_strlen(str1);
	len += ft_strlen(str2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*(str1 + i))
		*str++ = *(str1 + i++);
	i = 0;
	while (*(str2 + i))
		*str++ = *(str2 + i++);
	*str = '\0';
	free(str1);
	return (&(*(str - len)));
}
*/
