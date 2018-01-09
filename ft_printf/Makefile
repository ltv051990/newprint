#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/01 18:51:34 by tlutsyk           #+#    #+#              #
#    Updated: 2018/01/01 18:51:35 by tlutsyk          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SWITCH =		\033[
STYLE_NORMAL =	$(SWITCH)0m
STYLE_BOLD =	$(SWITCH)1m
COLOR_YELLOW =	$(SWITCH)93m
COLOR_GREEN = 	$(SWITCH)34m
COLOR_RED =		$(SWITCH)31m

C_FILES =  ft_printf.c ft_print_p.c ft_print_s.c ft_print_un_char.c\
			ft_print_un_string.c ft_print_integer.c ft_undigit.c\
			ft_print_x.c ft_print_o.c ft_add_unc_unstr.c
 
O_FILES = ft_printf.o ft_print_p.o ft_print_s.o ft_print_un_char.o\
			ft_print_un_string.o ft_print_integer.o  ft_undigit.o\
			ft_print_x.o ft_print_o.o ft_add_unc_unstr.o

FLAGS = -Wall -Wextra -Werror

all: $(addprefix ../objects/,$(O_FILES))

../objects/%.o: %.c
	@echo "$(STYLE_BOLD)$(COLOR_GREEN) $< has been compiled.$(STYLE_NORMAL)"
	@gcc -c $(FLAGS) $<  -I ../include -o $@ 
    
clean:
	@echo "$(STYLE_BOLD)$(COLOR_RED)All the object files (ft_printf) have been deleted.$(STYLE_NORMAL)"
	@rm -rf $(addprefix ../objects/,$(O_FILES))

fclean: clean
	@echo "$(STYLE_BOLD)$(COLOR_RED)$(NAME) has been deleted.$(STYLE_NORMAL)"

re: fclean all

.PHONY: clean all fclean re