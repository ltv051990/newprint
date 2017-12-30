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

# define SPEC_PER(x) (x == 's' || x == 'S' || x == 'p' || x == 'd' || x == 'D'\
|| x == 'o' || x == 'O' || x == 'u' || x == 'U' || x == 'x' || x == 'X'\
|| x == 'c' || x == 'C')

# define FLAGS_SIZE(y) (y == "hh" || y == 'h' || y == 'l' || y == 'll'\
						|| y == 'j' || y == 'z')

# define FLAGS_MODIF(a) (a == '#' || a == '0' || a ==  '-' || a ==  '+')

#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>
#include "../libft/libft.h"

typedef struct	s_struct
{
	int			min_size; 		// флаг розміру
	int			presizion; 		// флаг точності
	int			print_size;		// кількість байт для друку
	int			sharp;			// флаг шарпа
	char		plus; 			// флаг плюса
	char		minus; 			// флаг мінуса
	char		zero; 			// флаг нуля
	char		mod_size[3];	// специфікатор розміру
	size_t		write_count;	// кількість зчитаних байт
	char		*string;		// для друку
//	char		alpha;			// для символу
}				t_struct;

void	ft_print_s(va_list ap, t_struct *flags);
int		ft_presizion_s(t_struct *flags, int size_argum);
int		ft_min_pole_s(t_struct *flags, int size_argum);
void	ft_printf_s_with_size(t_struct *flags, int length, int min_size);
void	ft_print_s(va_list ap, t_struct *flags);
void	ft_print_c(va_list ap, t_struct *flags);
void	ft_print_p(va_list ap, t_struct *flags);
void	ft_print_unicode_char(va_list ap, t_struct *flags);
void	ft_print_unic_string(va_list ap, t_struct *flags);
int		count_bite(unsigned int nb);
void	ft_putchar_un(unsigned int nb);
int		ft_printf(const char *format, ...);

#endif