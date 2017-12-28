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
CFILES = ft_printf.c ft_print_p.c ft_print_s.c ft_memcmp.c ft_strcmp.c \
 ft_strncmp.c ft_isalpha.c ft_isdigit.c \
 ft_isalnum.c ft_isprint.c ft_islower.c ft_isupper.c ft_toupper.c ft_tolower.c \
 ft_atoi.c ft_strequ.c ft_strnequ.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
 ft_strcat.c ft_strncat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
 ft_strnew.c ft_itoa.c ft_strmap.c ft_strmapi.c ft_strsub.c ft_strjoin.c \
 ft_strtrim.c ft_strsplit.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
 ft_memset.c ft_memalloc.c ft_bzero.c ft_strdel.c ft_putchar.c ft_putstr.c \
 ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
 ft_putnbr_fd.c ft_strclr.c ft_striter.c ft_striteri.c ft_memdel.c \
 ft_strlcat.c ft_strlen.c ft_isascii.c ft_lstnew.c ft_lstdelone.c \
 ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_realloc.c ft_strjoin_def.c\
 ft_strcalc.c ft_sqrt.c ft_power.c ft_list_push_back.c
OFILES = $(CFILES:.c=.o)
all: $(NAME)

%.o: %.c
		@echo "$(STYLE_BOLD)$(COLOR_YELLOW)$< has been compiled.$(STYLE_NORMAL)"
		@gcc -c $? $(FILES)

$(NAME): $(OFILES)
	@echo "$(STYLE_BOLD)$(COLOR_GREEN)$(NAME) has been made.$(STYLE_NORMAL)"
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)

clean:
	@echo "$(STYLE_BOLD)$(COLOR_RED)All the object files have been deleted.$(STYLE_NORMAL)"
	@/bin/rm -f $(OFILES)

fclean: clean
	@echo "$(STYLE_BOLD)$(COLOR_RED)$(NAME) has been deleted.$(STYLE_NORMAL)"
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean