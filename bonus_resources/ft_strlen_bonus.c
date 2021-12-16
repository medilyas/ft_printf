/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:39:30 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/14 14:36:57 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

size_t	ft_strlen_bonus(const char *s)
{
	int		i;
	size_t	lenght;

	i = -1;
	lenght = 0;
	while (s[++i])
		++lenght;
	return (lenght);
}
