/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tower_of_hanoi.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 23:10:02 by onouaman          #+#    #+#             */
/*   Updated: 2018/11/22 13:32:47 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../libft/libft.h"
#include "get_next_line.h"

char 	**ft_create_tab(char **str);
void    ft_result(char ***str, int nbrmove, double time);
void	ft_move(char ***tables, int indx_from, int indx_to);
int		ft_whoisthis(int id);
int		ft_checkplace(int id_s1,int id_s2, int id_s3);
int		ft_findindx(int indx);
void	ft_swaptabs(char *str, char *str2);
int		ft_firstdisk(char **tab);
char	**ft_tower();
