/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnataliz <jnataliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:53:29 by jnataliz          #+#    #+#             */
/*   Updated: 2022/02/09 18:53:29 by jnataliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

void	test1(void);
void	test2(void);
void	test3(void);
void	test4(void);
void	test5(void);
void	test6(void);
void	test7(void);
void	test8(void);
void	test9(void);
void	test10(void);

void	test1(void)
{
	int	res;

	ft_putstr_fd("****** Test 1 ******\n", 1);
	res = ft_printf("Hello word\n");
	ft_putstr_fd("Hello word\n", 1);
	if (res != 11)
	{
		ft_putstr_fd("Fail! Expected 11, got: ", 1);
		ft_putnbr_fd(res, 1);
		ft_putstr_fd("\n",1);
	}
	else
		ft_putstr_fd("Ok!\n", 1);

	ft_putstr_fd("---------------\n", 1);
}

void	test2(void)
{
	// res = printf("Hello word\n");
	// Hello word -> output
	// res = 11   -> valore ritornato da ft_printf
	// res = printf("%c\n", 50);
	// 50 -> output?
   // 2 -> valore ritornato da ft_printf
  // res = 2 -> valore ritornato da ft_printf
	int	res;
	char c;

	c = 'Z';
	ft_putstr_fd("****** Test 2 ******\n", 1);
	res = ft_printf("%c\n", c);
	ft_putstr_fd("Z\n", 1);
	if (res != 2)
	{
		// Fail! Expected 2, got %d
		ft_putstr_fd("Fail! Expected 2, got: ", 1);
		ft_putnbr_fd(res, 1);
		ft_putstr_fd("\n",1);
	} else
		ft_putstr_fd("Ok!\n", 1);

	ft_putstr_fd("---------------\n", 1);
}

void	test3(void)
{	
	int res;

	ft_putstr_fd("****** Test 3 ******\n", 1);
	res = ft_printf("Hello wor%c\n", 'd');
	ft_putstr_fd("Hello word\n", 1);
	if (res != 11)
	{
		ft_putstr_fd("Fail! Expected 11, got: ", 1);
		ft_putnbr_fd(res, 1);
		ft_putstr_fd("\n",1);
	}
	else
		ft_putstr_fd("Ok!\n", 1);

	ft_putstr_fd("---------------\n", 1);
}

void	test4(void)
{	
	int res;

	ft_putstr_fd("****** Test 4 ******\n", 1);
	res = ft_printf("%d\n", -560);
	ft_putchar_fd('-', 1);
	ft_putnbr_fd(560, 1);
	ft_putchar_fd('\n', 1);
	if (res != 5)
	{
		ft_putstr_fd("Fail! Expected 4, got: ", 1);
		ft_putnbr_fd(res, 1);
		ft_putstr_fd("\n",1);
	}
	else
		ft_putstr_fd("Ok!\n", 1);

	ft_putstr_fd("---------------\n", 1);
}

void	test5(void)
{	
	int res;

	ft_putstr_fd("****** Test 5 ******\n", 1);
	res = ft_printf("This year is: %i!\n", 2022);
	ft_putstr_fd("This year is: 2022!", 1);
	ft_putchar_fd('\n', 1);
	if (res != 20)
	{
		ft_putstr_fd("Fail! Expected 20, got: ", 1);
		ft_putnbr_fd(res, 1);
		ft_putstr_fd("\n",1);
	}
	else
		ft_putstr_fd("Ok!\n", 1);

	ft_putstr_fd("---------------\n", 1);
}

void	test6(void)
{	
	int res;

	ft_putstr_fd("****** Test 6 ******\n", 1);
	res = ft_printf("Max int is: %d\n", 2147483647);
	ft_putstr_fd("Max int is: 2147483647\n", 1);
	if (res != 23)
	{
		ft_putstr_fd("Fail! Expected 23, got: ", 1);
		ft_putnbr_fd(res, 1);
		ft_putstr_fd("\n",1);
	}
	else
		ft_putstr_fd("Ok!\n", 1);

	ft_putstr_fd("---------------\n", 1);
}

void	test7(void)
{	
	int res;

	ft_putstr_fd("****** Test 7 ******\n", 1);
	res = ft_printf("Min int is: %i\n", -2147483647);
	ft_putstr_fd("Min int is: -2147483647\n", 1);
	if (res != 24)
	{
		ft_putstr_fd("Fail! Expected 24, got: ", 1);
		ft_putnbr_fd(res, 1);
		ft_putstr_fd("\n",1);
	}
	else
		ft_putstr_fd("Ok!\n", 1);

	ft_putstr_fd("---------------\n", 1);
}

void	test8(void)
{	
	int res;

	ft_putstr_fd("****** Test 8 ******\n", 1);
	res = ft_printf("%s\n", "Questa è una stringa");
	ft_putstr_fd("Questa è una stringa\n", 1);
	if (res != 22)
	{
		ft_putstr_fd("Fail! Expected 22, got: ", 1);
		ft_putnbr_fd(res, 1);
		ft_putstr_fd("\n",1);
	}
	else
		ft_putstr_fd("Ok!\n", 1);

	ft_putstr_fd("---------------\n", 1);
}

void	test9(void)
{	
	int res;

	ft_putstr_fd("****** Test 9 ******\n", 1);
	res = ft_printf("%x\n", 184545);
	ft_putstr_fd("2d0e1\n", 1);
	if (res != 6)
	{
		ft_putstr_fd("Fail! Expected 6, got: ", 1);
		ft_putnbr_fd(res, 1);
		ft_putstr_fd("\n",1);
	}
	else
		ft_putstr_fd("Ok!\n", 1);

	ft_putstr_fd("---------------\n", 1);
}

void	test10(void)
{	
	int res;

	ft_putstr_fd("****** Test 10 ******\n", 1);
	res = ft_printf("%u\n", -1);
	ft_putstr_fd("4294967295\n", 1);
	if (res != 11)
	{
		ft_putstr_fd("Fail! Expected 11, got: ", 1);
		ft_putnbr_fd(res, 1);
		ft_putstr_fd("\n",1);
	}
	else
		ft_putstr_fd("Ok!\n", 1);

	ft_putstr_fd("---------------\n", 1);
}
int	main(void)
{
	char *p = "test"; // {'t', 'e', 's', 't', '\0'}-
	int i = -1;
	int *y = &i;
// 0x..01 20  x
// 0x..02 20  i
// 0x..03 0x..02 y
// void *
	printf("%i\n", *y); // y -> i // stampa 20
	printf("sizeof(int*) = %li\nsizeof(long int) = %li\n", sizeof(int *), sizeof(long int));
	printf("0x%lx\n", (unsigned long int)y);
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	ft_printf("%X\n", -1);
	ft_printf("%x\n", -1);
	printf("%p\n", y);
	ft_printf("%p\n", y);
	printf("%p\n", p);
	ft_printf("%p\n", p);
}
