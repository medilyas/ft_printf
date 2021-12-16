/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:38:44 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/14 10:56:29 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*ft_strdup_bonus(const char *s1)
{
	char	*p;
	size_t	len;
	size_t	i;

	i = -1;
	len = ft_strlen_bonus(s1);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == 0)
		return (0);
	while (s1[++i])
		p[i] = s1[i];
	p[i] = '\0';
	return (p);
}
