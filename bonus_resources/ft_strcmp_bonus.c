/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:48:53 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/08 18:49:50 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	k;

	k = 0;
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
		k++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
