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

#include "../include/ft_printf.h"

/*
*** after outputs spec -> defoult struct flags
*/

void	ft_defolt_struct(t_struct *flags)
{
	flags->min_size = -1; 			// флаг розміру
	flags->presizion = -1; 			// флаг точності
	flags->print_size = 0;			// кількість байт для друку
	flags->space = -1;
	flags->plus = '\0'; 			// флаг плюса
	flags->minus = '\0'; 			// флаг мінуса
	flags->zero = '\0'; 			// флаг нуля
	flags->sharp = 0;				// флаг шарпа
	flags->mod_size = '\0';			// специфікатор розміру
	flags->count_nb = 0;			// к-ть симв в числі (-/+н,р)
	flags->char_costil = '\0';
}

/*
*** when i find a spec start modul.functions
*/

void 	ft_print_argument(char format, va_list ap, t_struct *flags)
{
	if (format == 's')
		ft_print_s(ap, flags, 0); // print string;
	if ((format == 'c' || format == '%') && (flags->char_costil = format))
		ft_print_c(ap, flags); // print char;
	if (format == 'p')
		ft_print_p(ap, flags); // print memory adress;
	if (format == 'S')
		ft_unic_string(ap, flags);// print UNICODE string;
	if (format == 'C')
		ft_print_unicode_char(ap, flags); // print unicode char
	if (format == 'd' || format == 'i')
		ft_print_integer(ap, flags); //print int (%d | %i)
	if (format == 'D')
		ft_print_big_integer(ap, flags); //print uns int(%D)
	if (format == 'o' || format == 'O')
		ft_print_o(ap, flags, format);
	if (format == 'u')
		ft_undigit(ap, flags);
	if (format == 'U')
		ft_un_big_digit(ap, flags);
	if (format == 'x' || format == 'X')
		ft_print_x(ap, flags, format);
}


int ft_read_nbsize_flags(char *format, t_struct *flags)
{
	int a;

	a = 1;
	if (*format == 'z' && (a = 1))
		flags->mod_size = 'z';
	else if (*format == 'j' && flags->mod_size != 'z' && (a = 1))
		flags->mod_size = 'j';
	else if (*format == 'l' && *(format + 1) == 'l' && \
		flags->mod_size != 'j' && flags->mod_size != 'z' && (a = 2))
		flags->mod_size = 'L';
	else if (*format == 'l' && flags->mod_size != 'L' && \
		flags->mod_size != 'j' && flags->mod_size != 'z' && (a = 1))
		flags->mod_size = 'l';
	else if (*format == 'h' && *(format + 1) != 'h' &&\
		flags->mod_size != 'l' && flags->mod_size != 'L' \
		&& flags->mod_size != 'j' && flags->mod_size != 'z' && (a = 1))
		flags->mod_size = 'h';
	else if (*format == 'h' && *(format + 1) == 'h' &&\
		flags->mod_size != 'h'&& flags->mod_size != 'l' \
		&& flags->mod_size != 'L' && flags->mod_size != 'j'\
		 && flags->mod_size != 'z' && (a = 2))
		flags->mod_size = 'H';
	return(a);
}

/*
*** read spec and write them to struct 
*/

int		ft_read_spec(char *format, va_list ap, t_struct *flags)
{
	int index = 0;

	while (format[index] != '\0' && !(SPEC_PER(format[index])))
	{	
		if (format[index] == ' ' && ++index)
			flags->space = 1;
		if (format[index] == '#' && ++index)
			flags->sharp = 1;
		if (format[index] == '-' && ++index)
			flags->minus = '-';
		if (format[index] == '+' && ++index)
			flags->plus = '+';
		if (format[index] == '0' && ++index)
			flags->zero = '0';
		if (ft_isdigit(format[index]))
			flags->min_size = ft_atoi(&format[index]);
		while (ft_isdigit(format[index]))
			index++;
		if (format[index] == '.' && ft_isdigit(format[index + 1]))
			flags->presizion = ft_atoi(&format[++index]);
		if (format[index] == '.' && !(ft_isdigit(format[index + 1])) && ++index)
			flags->presizion = 0;
		while (ft_isdigit(format[index]))
			index++;
		if (FLAGS_SIZE(format[index]))
			index += ft_read_nbsize_flags(&format[index], flags);
		if ((format[index] != '\0') && (INCORRECT_FORMAT(format[index])))
			index++;
	}
	if (SPEC_PER(format[index]))
		ft_print_argument(format[index], ap, flags);
	ft_defolt_struct(flags);
	return (index);
}

/*
*** one loop to read my format string
*/

void	ft_start_read(char *format, va_list ap, t_struct *flags)
{
	while (*format != '\0')
	{
		while (*format && *format != '%' && ++(flags->write_count))
		{
			ft_putchar(*format);
			format++;
		}
		if (*format == '%')
		{
			if (*format == '%' && *(format + 1) == '%' && *(format + 2) == '\0')
			{
				ft_putchar('%');
				++(flags->write_count);
				return ;
			}
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
