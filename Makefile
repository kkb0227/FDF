# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kykim <kykim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/09 11:53:48 by kykim             #+#    #+#              #
#    Updated: 2018/09/13 18:59:36 by kykim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFILES = *.c

OFILES = *.o

CGFLAGS = -Wall -Wextra -Werror

LIBFT = library/ft_libft

GNL = library/Get_Next_Line

all: $(NAME)

$(NAME):
		make -C $(LIBFT)
		make -C $(GNL)
		make -C minilibx_macos
		gcc $(CGFLAGS) -c $(CFILES) -I.
		gcc $(OFILES) -L $(LIBFT) -lft -L $(GNL) -lgnl -L minilibx_macos -lmlx -framework OpenGL -framework Appkit -o $(NAME)

clean:
	make -C $(LIBFT)/ clean
	make -C $(GNL)/ clean
	make -C minilibx_macos/ clean
	rm -f $(OFILES)

fclean: clean
		make -C $(LIBFT)/ fclean
		make -C $(GNL)/ fclean
		rm -f $(NAME)

re: fclean all

.PHONY: re all fclean clean