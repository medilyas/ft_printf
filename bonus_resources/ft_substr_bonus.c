/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 07:56:34 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/14 10:47:06 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slenght;
	char	*p;

	if (!s)
		return (0);
	slenght = ft_strlen_bonus(s);
	if (start >= slenght)
		return (ft_strdup_bonus(""));
	if (slenght >= len)
		p = (char *)malloc(sizeof(char) * len + 1);
	else
		p = (char *)malloc(sizeof(char) * (slenght - start) + 1);
	if (!p)
		return (0);
	i = 0;
	while (i < len && i < slenght)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
