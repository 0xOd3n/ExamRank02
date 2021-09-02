/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:01:25 by tlufulua          #+#    #+#             */
/*   Updated: 2021/09/02 15:00:24 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	ft_printf(const char *format, ...);

int	main()
{
	printf("(%i)\n", printf("1: Hola %s\n", "toto"));
	printf("(%i)\n", ft_printf("2: Hola %s\n", "toto"));
	printf("(%i)\n", printf("1: El número mágico es %d\n", 42));
	printf("(%i)\n", ft_printf("2: El número mágico es %d\n", 42));
	printf("(%i)\n", printf("1: %d, %d, %d, %d, %d\n", -42, 15, INT_MIN, INT_MAX, -0));
	printf("(%i)\n", ft_printf("2: %d, %d, %d, %d, %d\n", -42, 15, INT_MIN, INT_MAX, -0));
	printf("(%i)\n", printf("1: %s, %s, %s, %s\n", NULL, "hol\0a", "mundo", "Lorem ipsum"));
	printf("(%i)\n", ft_printf("2: %s, %s, %s, %s\n", NULL, "hol\0a", "mundo", "Lorem ipsum"));
	printf("(%i)\n", printf("1: %x, %x, %x, %x, %x\n", -42, 14, INT_MIN, INT_MAX, -0));
	printf("(%i)\n", ft_printf("2: %x, %x, %x, %x, %x\n", -42, 14, INT_MIN, INT_MAX, -0));
//	system("leaks a.out");
	return (0);
}
