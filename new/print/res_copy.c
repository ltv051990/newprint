/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 11:29:32 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/27 11:29:32 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void 	ft_print_argument(char format, va_list ap, size_t *write_count,\
		int presizion, int min_size)
{
	int size;
	char *a;

	a = va_arg(ap, char *);
	
}

int		ft_read_spec(char *format, va_list ap, size_t *write_count)
{
//	printf("format = %c\n", *format);
	int index = 0;
	int flag = 0;
	int min_size = 0;
	int presizion = 0;

	while (format[index] != '\0' && !(SPEC_PER(format[index])))
	{	
		if (format[index] == '-' && ++index)
			flag = -1;
		if (format[index] == '+' && ++index)
			flag = 1;
		if (ft_isdigit(format[index]))
			min_size = ft_atoi(&format[index]);
		while (ft_isdigit(format[index]))
			index++;
		if (format[index] == '.' && ft_isdigit(format[index + 1]))
			presizion = ft_atoi(&format[++index]);
		if (format[index] == '.' && !(ft_isdigit(format[index + 1]))\
				&& ++(*write_count))
			ft_putchar(format[index++]);
		while (ft_isdigit(format[index]))
			index++;
		if (SPEC_PER(format[index]))
			ft_print_argument(*format, ap, write_count, presizion, min_size);
	//		write(1, va_arg(ap, char *), presizion);
	//	(*write_count) = (*write_count) + presizion;
//			ft_putstr(va_arg(ap, char *));
//			ft_print_spec()
		// 	break ;
		//index++;
	}
	// printf("min_size = %d\n", min_size);
	// printf("presizion = %d\n", presizion);
	// printf("flag = %d\n", flag);
//	printf("index = %d\n", index);
	return (index);
}

void	ft_start_read(char *format, va_list ap, size_t *write_count)
{
//	(*write_count)++;
//	char *a;
//	a = va_arg(ap, char *);
//	printf("%s\n", format);
//	printf("a = %s\n", a);
	while (*format != '\0')
	{
		while (*format && *format != '%' && ++(*write_count))
		{
			ft_putchar(*format);
			format++;
		}
		if (*format == '%')
		{
	//		printf("%s\n", "I am find %");
			format++;
			if (*format == '%' && ++(*write_count))
				ft_putchar('%');
			else
				format = format + ft_read_spec(format, ap, write_count) + 1;
			
		}
//	format++;
	}
}

int		ft_printf(const char *format, ...)
{
	t_struct flags;

//	safe.index = 46;

//ft_aaaa(&safe);

int ft_aaaa(t_struct *safe)
{
	safe->index = 232;
}

	t_struct *xx;
	xx->index = 897;


	va_list ap;
	va_start(ap, format);
	size_t write_count = 0;

	if (*format == '\0')
		return (write_count);
	ft_start_read((char *)format, ap, &write_count);
	va_end(ap);
	return (write_count);
}

void	ft_print_s(va_list ap, t_struct *flags)
{ // друк строк
	int length;
	int min_size;

	if ((flags->string = va_arg(ap, char *)) == NULL)
		flags->string = "(null)";
	length = ft_presizion_s(flags, ft_strlen(flags->string));
	min_size = ft_min_pole_s(flags, length);
	ft_printf_s_with_size(flags, length, min_size);
	// if ((flags->string) == NULL)
	// {
	// 	length = ft_presizion_s(flags, 6);
	// 	min_size = ft_min_pole_s(flags, length);
	// 	if (min_size != 0)
	// 	{
	// 		if (flags->minus == '-')
	// 		{
	// 			write (1, "(null)", length);
	// 			while (min_size--)
	// 				write (1, " ", 1);
	// 		}
	// 		else
	// 		{
	// 			while (min_size--)
	// 				write (1, " ", 1);
	// 			write (1, "(null)", length);
	// 		}
	// 		flags->write_count += length + ft_min_pole_s(flags, length);
	// 	}
	// 	else
	// 	{
	// 		write (1, "(null)", length);
	// 		flags->write_count += length;
	// 	}
	// }
	// else
	// {
		// length = ft_presizion_s(flags, ft_strlen(flags->string));
		// min_size = ft_min_pole_s(flags, length);
		// if (min_size != 0)
		// {
		// 	if (flags->minus == '-')
		// 	{
		// 		write (1, flags->string, length);
		// 		while (min_size--)
		// 			write (1, " ", 1);
		// 	}
		// 	else
		// 	{
		// 		while (min_size--)
		// 			write (1, " ", 1);
		// 		write (1, flags->string, length);
		// 	}
		// 	flags->write_count += length + ft_min_pole_s(flags, length);
		// }
		// else
		// {
		// 	write(1, flags->string, length);
		// 	flags->write_count += length;
		// }
	// }
}
