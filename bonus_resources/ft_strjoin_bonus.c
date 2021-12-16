/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 09:10:47 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/07 22:16:04 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1lenght;
	size_t	s2lenght;
	size_t	i;
	char	*p;

	if (!s1 || !s2)
		return (0);
	s1lenght = ft_strlen_bonus(s1);
	s2lenght = ft_strlen_bonus(s2);
	p = (char *)malloc(sizeof(char) * (s1lenght + s2lenght + 1));
	if (!p)
		return (0);
	ft_memcpy(p, s1, s1lenght);
	p[s1lenght] = '\0';
	i = -1;
	while (++i < s2lenght)
		p[s1lenght + i] = s2 [i];
	p[s1lenght + i] = '\0';
	return (p);
}
