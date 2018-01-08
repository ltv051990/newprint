/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:01:46 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/25 18:01:47 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>
#include "../libft/libft.h"

# define SPEC_PER(x) (x == 's' || x == 'S' || x == 'p' || x == 'd' || x == 'D'\
|| x == 'o' || x == 'O' || x == 'u' || x == 'U' || x == 'x' || x == 'X'\
|| x == 'c' || x == 'C' || x == 'i' || x == '%')

# define FLAGS_SIZE(y) (y == 'h' || y == 'l' || y == 'j' || y == 'z')

# define FLAGS_MODIF(a) (a == '#' || a == '0' || a ==  '-' || a ==  '+' \
|| a == ' ' || a == '.')

#define FLAGS(w) (w == '#' || w ==  '-' || w ==  '+' \
|| w == ' ')

#define INCORRECT_FORMAT(z) (!SPEC_PER(z) && !FLAGS_MODIF(z) && !FLAGS_SIZE(z) \
		&& z != '\0')

typedef struct	s_struct
{
	int			min_size; 		// флаг розміру
	int			presizion; 		// флаг точності
	int			print_size;		// кількість байт для друку
	int			sharp;			// флаг шарпа
	int			space;			// флаг пробіла
	char		plus; 			// флаг плюса
	char		minus; 			// флаг мінуса
	char		zero; 			// флаг нуля
	char		mod_size;		// специфікатор розміру
	size_t		write_count;	// кількість зчитаних байт
	char		*string;		// для друку
	int 		count_nb;		// рахуємо кількість символів в числі (знак не враховуємо)
	char 		char_costil;	// костиль для процента
}				t_struct;

uint64_t	ft_atoi_long(char *str);
char		*ft_print_hex(int *tmp, int index);
char		*ft_find_hex(char *av);
int			ft_presizion_s(t_struct *flags, int size_argum);
int			ft_min_pole_s(t_struct *flags, int size_argum);
void		ft_printf_s_with_size(t_struct *flags, int length, int min_size);
void		ft_print_s(va_list ap, t_struct *flags, int prapor);
void		ft_print_c(char alpha, t_struct *flags);
void		ft_start_read_c(char format, va_list ap, t_struct *flags);
void		ft_print_p(va_list ap, t_struct *flags);
void		ft_print_unicode_char(va_list ap, t_struct *flags);
void		ft_unic_string(va_list ap, t_struct *flags);
int			count_bite(unsigned int nb);
void		ft_putchar_un(unsigned int nb);
void		ft_print_integer(va_list ap, t_struct *flags);
void		ft_print_big_integer(va_list ap, t_struct *flags);
void		ft_undigit(va_list ap, t_struct *flags);
void		ft_un_big_digit(va_list ap, t_struct *flags);
void		ft_print_x(va_list ap, t_struct *flags, char format);
void		ft_print_o(va_list ap, t_struct *flags, char format);
void		ft_take_unsigned_xo(uint64_t *b, va_list ap, t_struct *flags);
int			ft_printf(const char *format, ...);

#endif