/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:40:39 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/14 14:40:06 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	continue_process_diuxx(char **p, char *target, t_data data, int targlen)
{
	int		len;
	int		k;
	int		i;

	i = 0;
	if (target[0] == '-')
	{
		i = 1;
		k = 1;
		len = data.lenght - targlen;
	}
	else
	{
		k = 0;
		len = data.lenght - targlen - 1;
	}
	while (i <= len)
		(*p)[i++] = '0';
	while (i <= data.lenght && target[k])
		(*p)[i++] = target[k++];
	(*p)[i] = 0;
}

char	*process_diuxx(char *target, unsigned int targlen, t_data data)
{
	char	*p;
	int		i;

	p = (char *)malloc(sizeof(char) * (data.lenght + 1));
	if (!p)
		return (NULL);
	if (!ft_strcmp(target, "0") && !data.lenght)
		target = ft_strdup_bonus("");
	i = 0;
	if (target[0] == '-')
		p[i++] = '-';
	continue_process_diuxx(&p, target, data, targlen);
	return (p);
}

char	*do_prec_for_s(char *target, int targlen, t_data data)
{
	char	*p;
	int		i;

	p = NULL;
	i = -1;
	if (targlen <= data.lenght || *target == '\0')
		return (target);
	p = (char *)malloc(sizeof(char) * (data.lenght + 1));
	if (!p)
		return (NULL);
	while (++i < data.lenght)
		p[i] = target[i];
	if (target[0] != 0)
		p[i] = 0;
	return (p);
}

char	*do_precision(char *target, t_data data)
{
	int		targlen;
	char	*p;

	if (target && !target[0])
		targlen = data.lenght + 1;
	else
		targlen = ft_strlen_bonus(target);
	p = NULL;
	if (ft_strchr("cpdiuxX%", data.spec))
	{
		if (target[0] == '-')
			targlen -= 1;
		if (targlen >= data.lenght && ft_strcmp(target, "0")
			&& data.spec != 'c')
			return (target);
		p = process_diuxx(target, targlen, data);
	}
	if (data.spec == 's')
		p = do_prec_for_s(target, targlen, data);
	return (p);
}
