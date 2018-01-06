/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 16:23:25 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/24 16:23:35 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int main (void)
// {
// 	double item;
// 	char *a = "tata";

// 	item = 10.123046548;
// 	printf("%f\n", item);
// 	printf("%0123c\n", *a);
// 	printf("%016f\n", item);
// 	return (0);
// } // модифікатор мінімальної ширини поля !!!

// int main(void)
// {
// 	int i;

// 	for (i  = 1; i < 20; i++)
// 		printf("%8d %8d %8d\n", i, i*i, i*i*i);
// 	return (0);
// } // модифікатор мінімальної ширини поля !!!

int main(void)
{
//	int k = 21;
	// int b = -1;
//	size_t t = 18446744073709551615;
//	size_t a = b;

	long long int a = -1;

printf("%025llu\n", a);
printf("%025llU\n", a);
//printf("%d\n", sizeof(size_t));

//	printf("%lu\n", (unsigned long)&b);
//	printf("write count -> %d\n", printf("%d\n", k));
//	printf("%.4f\n", 123.1);
//	printf("%15.8d\n", 55);

//	printf("%10c\n", 'Z');
	return (0);
} // модифікатор точності

// int main(void)
// {
// 	float a = 1.1;
// 	printf(".............................\n");
// 	printf("по правому краю: %8d\n", 100);
// 	printf("по лівому краю: %-8d\n", 100);
// 	printf("%- 8.3f\n", a);
// 	return (0);
// } // модифікатор вирівнювання

// int main(int argc, const char * argv[])
// {
//     int a;
//     printf("%p\n",&a);
//     intptr_t p = (intptr_t)&a;
//     char s[2*sizeof(p)];
//     for(int i = 2*sizeof(p)-1; i >= 0; --i)
//     {
//        s[i] = "0123456789ABCDEF"[p & 0x0F];
//         p >>= 4;
//     }
//     for(int i = 0; i < 2*sizeof(p); ++i)
//           putc(s[i],stdout);
// } // друк адреси)))

static	unsigned int ft_is_basenb(char str)
{
	if ((str >= '0' && str <= '9') || (str >= 'A' && str <= 'F') ||\
		(str >= 'a' && str <= 'f'))
		return 1;
	return (0);
}

static unsigned int ft_base(char str, int base)
{
	if (str >= '0' && str <= '9')
		return (str - 48);
	if (str >= 'A' && str <= 'F') 
		return (--base - ('F' - str));
	//if (*str >= 'a' && *str <= 'f') 
	return (--base - ('f' - str));
}

static	unsigned int ft_base_calc(char *str, int base, int count)
{
	int power;
	unsigned int tmp;
	unsigned int res;

	power = 1;
	tmp = 0;
	res = 0;
	while (count--)
	{
		--str;
		res = (ft_base(*str, base) * power);
		power = power * base;
		tmp = tmp + res;
	}
	return (tmp);
}

unsigned long int ft_atoi_base(const char *str, int base)
{
	int negative;
	int count;


	negative = 1;
	count = 0;
	while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\t' ||\
	 *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_is_basenb(*str))
	{
		count++;
		str++;
	}
	return (ft_base_calc((char *)str, base, count) * negative);
}