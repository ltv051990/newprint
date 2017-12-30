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

#include "include/ft_printf.h"

/*
*** after outputs spec -> defoult struct flags
*/

void	ft_defolt_struct(t_struct *flags)
{
	flags->min_size = -1; 			// флаг розміру
	flags->presizion = -1; 			// флаг точності
	flags->print_size = 0;			// кількість байт для друку
	flags->plus = '\0'; 			// флаг плюса
	flags->minus = '\0'; 			// флаг мінуса
	flags->zero = '\0'; 			// флаг нуля
	flags->sharp = 0;				// флаг шарпа
	ft_bzero(flags->mod_size, 3);	// специфікатор розміру
}

/*
*** when i find a spec start modul.functions
*/

void 	ft_print_argument(char format, va_list ap, t_struct *flags)
{
	if (format == 's')
		ft_print_s(ap, flags); // print string;
	if (format == 'c')
		ft_print_c(ap, flags); // print char;
	if (format == 'p')
		ft_print_p(ap, flags); // print memory adress;
	if (format == 'S')
		ft_print_unic_string(ap, flags);// print UNICODE string;
	if (format == 'C')
	ft_print_unicode_char(ap, flags); // print unicode char
	if (format == 'd' || format == 'i')
		exit(0); //ft_
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
}

/*
*** read spec and write them to struct 
*/

int		ft_read_spec(char *format, va_list ap, t_struct *flags)
{
	int index = 0;

	while (format[index] != '\0' && !(SPEC_PER(format[index])))
	{	
		if (format[index] == '-' && ++index)
			flags->minus = '-';
		if (format[index] == '+' && ++index)
			flags->plus = '+';
		if (format[index] == '0' && ++index)/////// тут вставив
			flags->zero = '0'; //////////////////// тут втсавив
		if (ft_isdigit(format[index]))
			flags->min_size = ft_atoi(&format[index]);
		while (ft_isdigit(format[index]))
			index++;
		if (format[index] == '#' && ++index)/////////////////////////
			flags->sharp = 1; //////////////////////////////////////
		// if (format[index] == '0' && ++index)/////////////////////////
		// 	flags->zero = '0'; //////////////////////////////////////
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

/*
*** one loop to read my format string
*/

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

/*
*** inizial struct and inizial va_arg
*/

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
