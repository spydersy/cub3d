# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 06:55:38 by abelarif          #+#    #+#              #
#    Updated: 2020/11/10 07:20:25 by abelarif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3d

SRCS=cub3d.c                 ./LBFT/ft_isascii.c     ./LBFT/ft_putendl_fd.c  ./LBFT/ft_strncmp.c \
cub3d_utils.c                ./LBFT/ft_isdigit.c     ./LBFT/ft_putnbr_fd.c   ./LBFT/ft_strnstr.c \
data.c                       ./LBFT/ft_isprint.c     ./LBFT/ft_putstr_fd.c   ./LBFT/ft_strrchr.c \
get_data.c                   ./LBFT/ft_itoa.c        ./LBFT/ft_split.c       ./LBFT/ft_strtrim.c \
./GNL/get_next_line.c        ./LBFT/ft_memccpy.c     ./LBFT/ft_strchr.c      ./LBFT/ft_substr.c  \
./GNL/get_next_line_utils.c  ./LBFT/ft_memchr.c      ./LBFT/ft_strdup.c      ./LBFT/ft_tolower.c \
./LBFT/ft_atoi.c             ./LBFT/ft_memcmp.c      ./LBFT/ft_strjoin.c     ./LBFT/ft_toupper.c \
./LBFT/ft_bzero.c            ./LBFT/ft_memcpy.c      ./LBFT/ft_strlcat.c     link.c     		 \
./LBFT/ft_calloc.c           ./LBFT/ft_memmove.c     ./LBFT/ft_strlcpy.c     main.c     		 \
./LBFT/ft_isalnum.c          ./LBFT/ft_memset.c      ./LBFT/ft_strlen.c      map.c      		 \
./LBFT/ft_isalpha.c          ./LBFT/ft_putchar_fd.c  ./LBFT/ft_strmapi.c     my_split.c 		 \

$(NAME):
	clang -Wall -Werror -Wextra -g $(SRCS)

