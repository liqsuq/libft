/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:52:54 by kadachi           #+#    #+#             */
/*   Updated: 2024/11/09 19:14:52 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	n /= 10;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ret;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = count_digits(n);
	ret = malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
	}
	ret[len--] = '\0';
	while (n != 0)
	{
		ret[len--] = n % 10 + '0';
		n /= 10;
	}
	return (ret);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *s1 = ft_itoa(123);
// 	char *s2 = ft_itoa(-123);
// 	char *s3 = ft_itoa(0);
// 	char *s4 = ft_itoa(2147483647);
// 	char *s5 = ft_itoa(-2147483648);
// 	printf("%s\n", s1);
// 	printf("%s\n", s2);
// 	printf("%s\n", s3);
// 	printf("%s\n", s4);
// 	printf("%s\n", s5);
// 	free(s1);
// 	free(s2);
// 	free(s3);
// 	free(s4);
// 	free(s5);
// 	return (0);
// }
