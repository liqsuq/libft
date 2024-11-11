/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:32:54 by kadachi           #+#    #+#             */
/*   Updated: 2024/11/10 16:43:34 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char const c, char const *set)
{
	while (*set != '\0')
		if (*set++ == c)
			return (1);
	return (0);
}

static size_t	trimmed_start(char const *s, char const *set)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!is_charset(s[i], set))
			break ;
		i++;
	}
	return (i);
}

static size_t	trimmed_end(char const *s, char const *set)
{
	size_t	i;

	i = ft_strlen(s);
	while (i-- > 0)
		if (!is_charset(s[i], set))
			break ;
	return (i);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*ret;
	size_t	start;
	size_t	size;

	if (s == NULL || set == NULL)
		return (NULL);
	start = trimmed_start(s, set);
	size = trimmed_end(s, set) - start + 1;
	ret = ft_substr(s, start, size);
	return (ret);
}

// #include <stdio.h>
// int main(void)
// {
// 	char	*ptr;
// 	ptr = ft_strtrim("Hello, World!", "Hell!");
// 	if (!ptr)
// 		return (1);
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	return (0);
// }