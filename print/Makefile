#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 22:16:23 by tlutsyk           #+#    #+#              #
#    Updated: 2017/12/28 22:16:23 by tlutsyk          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SWITCH =		\033[
STYLE_NORMAL =	$(SWITCH)0m
STYLE_BOLD =	$(SWITCH)1m
COLOR_YELLOW =	$(SWITCH)93m
COLOR_GREEN = 	$(SWITCH)34m
COLOR_RED =		$(SWITCH)31m

NAME = libftprintf.a
CC = gcc 
IDIR = /include
CFLAGS = -I$(IDIR)
ODIR = obj
LDIR = ./libft
LIBFT = $(LDIR)/libft.a
SDIR = src
SRC = ft_printf.c \
 	  bloks/ft_print_p.c \
	  bloks/ft_print_s.c 
_OBJ = $(SRC:%.c=%.o)
_DEPS = ft_printf.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: $(NAME)

obj:
	@mkdir -p $(ODIR)
	@mkdir -p $(ODIR)/bloks

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@echo "$(STYLE_BOLD)$(COLOR_YELLOW)$< has been compiled.$(STYLE_NORMAL)"
	@$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): obj	$(LIBFT) $(OBJ)
			@echo "$(STYLE_BOLD)$(COLOR_GREEN)$(NAME) has been made.$(STYLE_NORMAL)"
			@cp libft/libft.a ./$(NAME)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)

$(LIBFT):
	@make -C $(LDIR)
rmlibobj:
	@make clean -C $(LDIR)

rmlib:
	@/bin/rm -f $(LIBFT)

.PHONY: all clean fclean re
.NOTPARALLEL: all clean fclean re

clean : rmlibobj
	@echo "$(STYLE_BOLD)$(COLOR_RED)All the object files have been deleted.$(STYLE_NORMAL)"
	@/bin/rm -rf $(ODIR)

fclean: clean rmlib
	@echo "$(STYLE_BOLD)$(COLOR_RED)$(NAME) has been deleted.$(STYLE_NORMAL)"
	@/bin/rm -f $(NAME)

re : fclean all