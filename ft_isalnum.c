/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:12:02 by kadachi           #+#    #+#             */
/*   Updated: 2024/11/10 15:17:47 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// static int xor_nonbitwise(int a, int b)
// {
// 	return (!a != !b);
// }
// int main(void)
// {
// 	int	i;
// 	i = -256;
// 	while (i < 256)
// 	{
// 		printf("%d -> ", i);
// 		if (xor_nonbitwise(ft_isalnum(i), isalnum(i)))
// 		{
// 			printf("NG\n");
// 			return (1);
// 		}
// 		else
// 			printf("OK\n");
// 		i++;
// 	}
// 	printf("\nSuccess!\n");
// 	return (0);
// }
