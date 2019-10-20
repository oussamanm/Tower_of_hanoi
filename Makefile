# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: onouaman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 19:32:21 by onouaman          #+#    #+#              #
#    Updated: 2018/11/22 13:31:20 by onouaman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tower

LIBFT = ./libft/libft.a

SRCS = ./srcs/*.c

all :
	gcc -o $(NAME) $(SRCS) $(LIBFT)

$(NAME) : all

clean : clean
	rm -f $(NAME)

re : clean all
