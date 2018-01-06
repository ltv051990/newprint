/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 00:23:32 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/28 00:23:33 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>

int		main(void)
{
	// char *a;
	// char *b;
	// char *c = NULL;
	// // a = "taras";
	// b = "123456789"; 

	// printf("\nmy printf res = %d\n", ft_printf("\nasdasd %s \nxaxa\n %s \nxaxa\n %s", c, a, b));
	// printf("\nor printf res = %d\n",    printf("\nasdasd %s \nxaxa\n %s \nxaxa\n %s", c, a, b));

	////////////////////////////////////////////////////////////////////////////////////
	//					STRING		//
	////////////////////////////////////////////////////////////////////////////////////
	
	// char **a = (char**)malloc(sizeof(char *) * 4);
	// a[0] = ft_strdup("123");
	// a[1] = ft_strdup("456");
	// a[2] = ft_strdup("789");
	// a[3] = NULL;
	// char **b;
	// b = a;
	// int my;
	// int ne_may;
	// while (*a)
	// {
	// 	my = ft_printf("\nmy little printf = %15s", *a++);
	// 	printf("\nmy%d\n", my);
	// 	ne_may = printf("\nmy little printf = %15s", *b++);
	// 	printf("\nne_may%d\n", ne_may);
	// }
	// ft_printf("\nmy little printf = %s", *a);

	////////////////////////////////////////////////////////////////////////////////////
	//					CHAR		//
	////////////////////////////////////////////////////////////////////////////////////
	
	// char a = 'z';
	// int res;
	// char *z = "taras";
	// res = ft_printf("\nyoyo%10c%s\n%s", a, NULL, z);
	// printf("\n%d\n", res);
	// res = printf("\nyoyo%10c%s\n%s", a, NULL, z);
	// printf("\n%d\n", res);

	////////////////////////////////////////////////////////////////////////////////////
	//		PRINT MEMORY ADRESS		//
	////////////////////////////////////////////////////////////////////////////////////
	
	// int *t;

	// printf("%    d\n", ft_printf("adress ->%-100p %-10s %110c", &t, NULL, 65));
	// printf("%    d\n",    printf("adress ->%-100p %-10s %110c", &t, NULL, 65));

	////////////////////////////////////////////////////////////////////////////////////
	//		PRINT UNICODE CHAR		//
	////////////////////////////////////////////////////////////////////////////////////

	setlocale(LC_ALL, "");
	// wchar_t value = L'й';
	printf("my pr->%d\n", ft_printf("%C, %C", L'ÊM-^ZM-^V', L'ÿ≠'));
	printf("nm pr->%d\n",  printf("%lc, %lc", L'ÊM-^ZM-^V', L'ÿ≠'));


	printf("my pr->%d\n", ft_printf("{%05.c}", 65));
	printf("nm pr->%d\n",  printf("{%05.c}", 65));

	printf("my pr->%d\n", ft_printf("{%03c}", 0));
	printf("nm pr->%d\n",  printf("{%03c}", 0));

	printf("my pr->%d\n", ft_printf("%05c", 42));
	printf("nm pr->%d\n",  printf("%05c", 42));

	// ft_printf("\n%5.2s is a string", "");
	// printf("\n%5.2s is a string", "");
	// printf("%+d", 4242424242424242424242);
	//////////////////////////////////////////////////////
	//////////////////////////////
	// printf("mcount= %d\n", ft_printf("%+-5.6hhi", 214748364));
	// printf("count = %d\n",    printf("%+-5.6hhi", 214748364));
	//		PRINT UNICODE STRING		//
	////////////////////////////////////////////////////////////////////////////////////

	// setlocale(LC_ALL, "");
	// wchar_t value = L'й';

	// write(1, "\n", 1);
	// printf("mcount= %d\n", ft_printf("my printf %S  %10c %10.5s %10C %p", L"не а просто", 65, "taraspapa", 666, &value));
	// printf("count = %d\n",    printf("nm printf %S  %10c %10.5s %10C %p", L"не а просто", 65, "taraspapa", 666, &value));
	////////////////////////////////////////////////////////////////////////////////////
	//		PRINT INTEGER		//
	////////////////////////////////////////////////////////////////////////////////////}
	// printf("\n%d\n", ft_printf("%+10.zD", -1));
	// printf("\n%d\n",    printf("%+10.zD", -1));
	return (0);
}
