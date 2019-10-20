/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 23:25:55 by onouaman          #+#    #+#             */
/*   Updated: 2018/11/01 22:16:09 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_returns(char *tab, char **line, long int *stc_indx, long int *i)
{
	size_t	lentab;

	lentab = ft_strlen(tab);
	while (tab[*stc_indx] != 0 && tab[*stc_indx] != 10 && *i <= (int)lentab)
		(*stc_indx)++;
	if (((*stc_indx == *i && tab[*stc_indx] == '\n') ||
				tab[*i] != '\0') && *i < (int)lentab)
	{
		line[0] = (char *)malloc(sizeof(char) * ((*stc_indx - *i) + 1));
		line[0] = ft_strsub(&tab[*i], 0, (((*stc_indx)++) - *i));
		return (1);
	}
	line[0] = NULL;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*tab;
	static int		old_fd;
	static long int	stc_indx;
	long int		i;
	char			*temp;

	if ((old_fd != 0 && old_fd != fd) || stc_indx == 0)
	{
		stc_indx = 0;
		tab = (char *)malloc(1);
	}
	temp = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((i = read(fd, temp, BUFF_SIZE)))
	{
		if (i < 0)
			return (-1);
		temp[i] = '\0';
		tab = ft_strjoin(tab, temp);
	}
	i = stc_indx;
	old_fd = fd;
	return (ft_returns(tab, &line[0], &stc_indx, &i));
}
