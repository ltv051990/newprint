/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 14:39:48 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/25 14:39:50 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_defolt_struct(t_struct *flags)
{
	flags->min_size = -1; 		// флаг розміру
	flags->presizion = -1; 		// флаг точності
	flags->print_size = 0;		// кількість байт для друку
	flags->plus = '\0'; 			// флаг плюса
	flags->minus = '\0'; 			// флаг мінуса
	flags->zero = '\0'; 			// флаг нуля
	flags->sharp = 0;
	ft_bzero(flags->mod_size, 3);	// специфікатор розміру
}

void 	ft_print_argument(char format, va_list ap, t_struct *flags)
{
	if (format == 's')
		ft_print_s(ap, flags);
	if (format == 'c')
		ft_print_c(ap, flags);
	if (format == 'p')
		ft_print_p(ap, flags);
	if (format == 'S')
		exit(0);
	if (format == 'd' || format == 'i')
		exit(0);
	if (format == 'D')
		exit(0);
	if (format == 'o')
		exit(0);
	if (format == 'O')
		exit(0);
	if (format == 'u')
		exit(0);
	if (format == 'U')
		exit(0);
	if (format == 'x')
		exit(0);
	if (format == 'X')
		exit(0);
	if (format == 'C')
		exit(0);
}

int		ft_read_spec(char *format, va_list ap, t_struct *flags)
{
	int index = 0;

	while (format[index] != '\0' && !(SPEC_PER(format[index])))
	{	
		if (format[index] == '-' && ++index)
			flags->minus = '-';
		if (format[index] == '+' && ++index)
			flags->plus = '+';
		if (ft_isdigit(format[index]))
			flags->min_size = ft_atoi(&format[index]);
		while (ft_isdigit(format[index]))
			index++;
		if (format[index] == '#' && ++index)/////////////////////////
			flags->sharp = 1; //////////////////////////////////////
		if (format[index] == '0' && ++index)/////////////////////////
			flags->zero = '0'; //////////////////////////////////////
		if (format[index] == '.' && ft_isdigit(format[index + 1]))
			flags->presizion = ft_atoi(&format[++index]);
		if (format[index] == '.' && !(ft_isdigit(format[index + 1]))\
				&& ++(flags->write_count))
			ft_putchar(format[index++]);
		while (ft_isdigit(format[index]))
			index++;
		if (!(SPEC_PER(format[index]))) //////////////////////////////
			index++;//////////////////////////////////////////////////

	}
	if (SPEC_PER(format[index]))
		ft_print_argument(format[index], ap, flags); //функц поч ініц
		ft_defolt_struct(flags); //функція яка зануляє стуруру перед поч зч ін
	return (index);
}

void	ft_start_read(char *format, va_list ap, t_struct *flags)
{
	while (*format != '\0') // читаю за один прохід строку аргументів
	{
		while (*format && *format != '%' && ++(flags->write_count))
		{
			ft_putchar(*format);
			format++;
		}
		if (*format == '%')
		{
			format++;
			if (*format == '%' && ++(flags->write_count))
				ft_putchar('%');
			else
				format = format + ft_read_spec(format, ap, flags) + 1;
			
		}
	}
}

int		ft_printf(const char *format, ...)
{
	t_struct flags;
	flags.write_count = 0;
	va_list ap;
	va_start(ap, format);
	ft_defolt_struct(&flags);

	if (*format == '\0')
		return (0);
	ft_start_read((char *)format, ap, &flags);
	va_end(ap);
	return (flags.write_count);
}
