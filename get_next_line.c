	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:19:51 by maraujo-          #+#    #+#             */
/*   Updated: 2020/05/07 21:46:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_strfree(char **str)
{
	if (str == 0)
		return ;
	if (*str)
		free(*str);
	*str = 0;
}

int				ft_strcut (char **string, char **line, int posicaoDivisao)
{
	char	*temp;
	int		counter;
	int		counter2;

	if (!(*line = malloc(sizeof(char) * (posicaoDivisao + 1))))
		return (-1);
	counter = 0;
	while (counter != posicaoDivisao)
	{
		(*line)[counter] = (*string)[counter];
		counter++;
	}
	(*line)[counter] = '\0';
	if (ft_strlen(*string) - posicaoDivisao != 0)
	{
		if (!(temp = malloc(sizeof(char) * (ft_strlen(*string) - posicaoDivisao))))
			return (-1);	
		posicaoDivisao++;
		counter2 = 0;
		while ((*string)[posicaoDivisao])
		{
			temp[counter2] = (*string)[posicaoDivisao];
			posicaoDivisao++;
			counter2++;
		}
		temp[counter2] = '\0';
		ft_strlcpy(*string, temp, ft_strlen(*string));
		ft_strfree(&temp);
		return (1);
	}
	ft_strfree (string);
	return (0);
}

int				ft_new_line(const char *str, int ret)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	if (ret == 0)
		return (i);
	return (-1);
}

char *ft_strconcat(char *str1, char *str2)
{
	int 	len;
	char	*concat;
	int		cont;

	cont = 0;
	len = ft_strlen(str1) + ft_strlen(str2);
	if (!(concat = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (str1)
	{
		while (str1[cont])
		{
			concat[cont] = str1[cont];
			cont++;
		}
	}
	if (str2)
	{
		while (*str2)
		{
			concat[cont] = *str2;
			cont++;
			str2++;
		}
	}
	concat[cont] = '\0';
	if (str1)
		ft_strfree(&str1);
	return (concat);
}

int	get_next_line(int fd, char **line)
{
	char		temp[BUFFER_SIZE + 1];
	static int	ret;
	static char	*resto;
	int			i;

	if (line == 0 || fd < 0 || BUFFER_SIZE < 1 || read(fd, temp, 0) < 0)
		return (-1);
	while (1)
	{
		ret = read(fd, temp, BUFFER_SIZE);
		temp[ret] = '\0';
		resto = ft_strconcat(resto, temp);
		if ((i = ft_new_line(resto, ret)) != -1)
			return (ft_strcut(&resto, line, i));
	}
}