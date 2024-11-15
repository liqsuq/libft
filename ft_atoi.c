/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:00:04 by kadachi           #+#    #+#             */
/*   Updated: 2024/11/11 12:41:06 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		num;

	sign = 1;
	num = 0;
	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n'
		|| *nptr == '\r' || *nptr == '\t' || *nptr == '\v')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num *= 10;
		num += *nptr - '0';
		nptr++;
	}
	num *= sign;
	return (num);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
// 	printf("%d\n", atoi("1000"));
// 	printf("%d\n", ft_atoi("1000"));
// 	printf("%d\n", atoi("  -1234"));
// 	printf("%d\n", ft_atoi("  -1234"));
// 	printf("%d\n", atoi("  -1234ab567"));
// 	printf("%d\n", ft_atoi("  -1234ab567"));
// 	printf("%d\n", atoi("-2147483648"));
// 	printf("%d\n", ft_atoi("-2147483648"));
// 	printf("%d\n", atoi("2147483647"));
// 	printf("%d\n", ft_atoi("2147483647"));
// 	printf("%d\n", atoi("++1234"));
// 	printf("%d\n", ft_atoi("++1234"));
// 	printf("%d\n", atoi("+1234"));
// 	printf("%d\n", ft_atoi("+1234"));
// 	printf("%d\n", atoi("--1234"));
// 	printf("%d\n", ft_atoi("--1234"));
// 	printf("%d\n", atoi("2147483650"));
// 	printf("%d\n", ft_atoi("2147483650"));
// 	return (0);
// }
