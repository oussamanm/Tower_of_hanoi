/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tower_of_hanoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:01:23 by onouaman          #+#    #+#             */
/*   Updated: 2018/11/22 13:55:59 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "tower_of_hanoi.h"

int id_str = 1;
int id_str2 = 0;
int id_str3 = 0;

int n;

int		ft_strlenchar(char *str, char c)
{
	int i,resu;
	i = resu = 0;

	while (str[i] != '\0')
	{
		if (str[i] == c)
			resu++;
		i++;
	}
	return (resu);
}

void	ft_colortxt(char c)
{
	if (c == 'g')
		printf("\033[0;32m");
	else if (c == 'y')
		printf("\033[0;33m");
	else if (c == 'd')
		printf("\033[0m");
}


char 	**ft_create_tab(char **str)
{
	int i  =0;
	int j = 0;
	str = (char **)malloc(sizeof(char *) * n + 1);
	while (i < n)
		str[i++] = (char *)malloc(sizeof(char) * (n * 2));
	i = 0;
	while (i < n)
	{
		j = 0;
		while(j < (n*2) - 1)
		{
			str[i][j] = '.';
			j++;
		}
		str[i][j] = '\0';
		i++;
	}
	str[i] = "\0";
	return (str);
}

////////********** Print Result ********////////
void    ft_result(char ***tables, int nbrmove, double time)
{
	int i,j;
	i  = 0;

	printf("Moves : ");
	ft_colortxt('g');
	printf("%d",nbrmove);
	ft_colortxt('d');
	printf("	in : ");
	ft_colortxt('y');
	printf("%f",time);
	ft_colortxt('d');
	printf(" Sec\n");

	int code_color = 31;
	int code_color2 = 0;
	while (i < n)
	{
		j = 0;
		while (j < 3)
		{
			int lendisk = ft_strlenchar(tables[j][i],'#');

			if (n < 8 && lendisk != 0)
			{
				code_color = 30 + (lendisk / 2);
				printf("\033[1;%sm",ft_itoa(code_color));
				printf("%s\t",tables[j][i]);
				ft_colortxt('d');
			}
			else if (n >= 8 && lendisk != 0)
			{
				if (((lendisk / 2) % 2) == 0)
				{
					printf("\033[22;37m");
					code_color2 = 1;
				}
				else
				{
					printf("\033[37;1m");
					code_color2 = 0;
				}
				printf("%s\t",tables[j][i]);
				ft_colortxt('d');
			}
			else
			{
				ft_colortxt('d');
				printf("%s\t",tables[j][i]);
			}
			j++;
		}

		i++;
		printf("\n");
	}
}

int			ft_findchar(char *str, char c)
{
	int i,resu;

	i = resu = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			resu++;
		i++;
	}
	return (resu);
}

//////********** Update vrd ID_STRi *********/////////
void ft_corrindx(char ***tables)
{
	int i,j,rt_find;

	i = 0;
	while (i < 3)
	{
		j = 0;
		rt_find = 0;
		while (j < n)
		{
			if ((rt_find = ft_findchar(tables[i][j],'#')) != 0)
			{
				int id;
				id = (rt_find / 2) + 1;
				if (i == 0)
					id_str = id;
				else if (i == 1)
					id_str2 = id;
				else if (i == 2)
					id_str3 = id;
				break ;
			}
			else
			{
				if (i == 0)
					id_str = 0;
				else if (i == 1)
					id_str2 = 0;
				else if (i == 2)
					id_str3 = 0;
			}
			j++;
		}
		i++;
	}
}

void	ft_move(char ***tables, int indx_from, int indx_to)
{
	int indxfrst_diskf;
	int indxfrst_diskt;

	indx_from--;
	indx_to--;
	indxfrst_diskf = ft_firstdisk(tables[indx_from]);
	indxfrst_diskt = ft_firstdisk(tables[indx_to]);
	if (indxfrst_diskt == -1)
		indxfrst_diskt = n - 1;
	else
		indxfrst_diskt--;
	ft_swaptabs(tables[indx_from][indxfrst_diskf],tables[indx_to][indxfrst_diskt]);
}

int		ft_whoisthis(int id)
{
	if (id == id_str)
		return (1);
	if ((n % 2) == 0)
	{
		if (id == id_str2)
			return (2);
		else if (id == id_str3)
			return (3);
	}
	else
	{
		if (id == id_str3)
			return (3);
		else if (id == id_str2)
			return (2);
	}
	return (-1);
}

int		ft_checkplace(int id_s1,int id_s2, int id_s3)
{
	if (id_s1	< id_s2 || id_s2 == 0)
		return(ft_whoisthis(id_s2));
	else if (id_s1 < id_s3 || id_s3 == 0)
		return(ft_whoisthis(id_s3));
	else
		return (-1);
}

int		ft_findindx(int indx)
{
	if (indx == id_str)
		return (1);
	else if (indx == id_str2)
		return (2);
	else if (indx == id_str3)
		return (3);
	else
		return (-1);
}

//////******* Swap two Table *****//////
void	ft_swaptabs(char *str, char *str2)
{
	int i =0;
	int j = 0;

	char *new = (char *)malloc(sizeof(char) * strlen(str));

	strcpy(new,str);
	strcpy(str,str2);
	strcpy(str2,new);
}

////// find first dist and return his index
int		ft_firstdisk(char **tab)
{
	int i,j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n*2 -1)
		{
			if (tab[i][j] == '#')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

char	**ft_tower()
{
	int i = 0;
	int j = 0;

	char **str;
	char **str2;
	char **str3;
	char ***tables;

	clock_t begin = clock();
	double time_spent;
	clock_t end;

	//////// Creat Tab //////////////
	tables = (char ***)malloc(sizeof(char **) * 4);

	str = ft_create_tab(str);
	str2 = ft_create_tab(str2);
	str3 = ft_create_tab(str3);

	tables[0] = str;
	tables[1] = str2;
	tables[2] = str3;

	/////// Fill with hashtag ///////
	i = 0;
	int cmpt = 0;
	int newn = n;
	int square = 1;
	while (i < n)
	{
		j = (((newn*2) - 1)/2) ;
		cmpt = 0;
		while (cmpt < square)
		{
			str[i][j] = '#';
			cmpt++;
			j++;
		}
		square += 2;
		newn--;
		i++;
	}

	///////************************  Move Disk  ********////

	int index = 1;
	int *p_indx;
	int nbrmove;

	//////// printf tabs ///////
	ft_result(tables,nbrmove,time_spent);
	usleep(100000);
	system("clear");

	nbrmove = 0;
	while (1)
	{
		////************ Find Where's index
		int rt_find;
		int rt_checkp;

		if (index > n)
			index = 1;
		rt_find = ft_findindx(index);

		if (rt_find == 1)
			p_indx = &id_str;
		else if (rt_find == 2)
			p_indx = &id_str2;
		else if (rt_find == 3)
			p_indx = &id_str3;

		if (rt_find != -1)
		{
			////************* Check Place and return index place
			if ((n % 2) == 0)
			{
				if (*p_indx == id_str)
					rt_checkp = ft_checkplace(*p_indx,id_str2,id_str3);
				else if (*p_indx == id_str2)
					rt_checkp = ft_checkplace(*p_indx,id_str3,id_str);
				else if (*p_indx == id_str3)
					rt_checkp = ft_checkplace(*p_indx,id_str,id_str2);
			}
			else
			{
				if (*p_indx == id_str)
					rt_checkp = ft_checkplace(*p_indx,id_str3,id_str2);
				else if (*p_indx == id_str2)
					rt_checkp = ft_checkplace(*p_indx,id_str,id_str3);
				else if (*p_indx == id_str3)
					rt_checkp = ft_checkplace(*p_indx,id_str2,id_str);
			}

			if (rt_checkp != -1)
			{
				ft_move(tables,ft_whoisthis(*p_indx),rt_checkp);
				index++;
				ft_corrindx(tables);
				nbrmove++;
			}
			else /// No Place
				index++;
		}
		else //doesn't find it
			index++;

		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		system("clear");
		ft_result(tables,nbrmove,time_spent);
		usleep(150000);

		if (id_str == 0 && id_str2 == 0 && id_str3 == 1)
			break ;
	}
	free(tables);
	return (str);
}

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	char **str;
	char head[1000];

	system("clear");
	//////*** Read Header ***//////
	char *strhead;
	int fd;
	if ((fd = open("header",O_RDONLY)) == -1)
	{
		puts("Error Read File HEADER");
		return (0);
	}
	while (get_next_line(fd,&strhead) != 0)
	{
		ft_strcat(head,strhead);
		ft_strcat(head,"\n");
		printf("%s\n",strhead);
		usleep(200000);
	}
	if (close(fd) == -1)
	{
		puts("Error Close file HEADER");
		return (0);
	}

	//////*** Tower ******////
	char s[50];
	printf("\nEnter the nombre of DISK :");
	scanf("%s",s);
	while (1)
	{
		if ((n = ft_atoi(s)) != 0)
		{
			str = ft_tower();
			break ;
		}
		else
		{
			printf("\nEnter the nombre of DISK :");
			scanf("%s",s);	
		}
	}

	return (0);
}
