/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_all_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:41:07 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/14 14:40:21 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*continue_process2(char *target, t_data data, t_index *index)
{
	char	*p;

	if (data.space && index->nbr_sign != -1)
	{
		p = ft_strdup_bonus(target);
		free(target);
		index->freed = 1;
		target = do_space(p, data, index);
		if (p != target)
			free(p);
	}
	return (target);
}

char	*continue_process1(char *target, t_data data, t_index *index)
{
	char	*p;

	if (((data.plus || data.hash) && ft_strchr("dixX", data.spec))
		|| data.spec == 'p')
	{
		p = ft_strdup_bonus(target);
		free(target);
		index->freed = 1;
		target = do_plus_hash(p, data);
		if (p != target)
			free(p);
	}
	index->targlen = ft_strlen_bonus(target);
	if (data.width)
	{
		p = ft_strdup_bonus(target);
		free(target);
		index->freed = 1;
		target = do_width(p, data);
		if (p != target)
			free(p);
	}
	return (continue_process2(target, data, index));
}

char	*do_process(char *comb, char *target, t_index *index)
{
	char	*p;
	t_data	data;

	set_data(comb, &data);
	if (ft_strchr("xX", data.spec) && !ft_strcmp(target, "0"))
		data.hash = 0;
	if (data.spec == '%')
	{
		target = (char *)malloc(sizeof(char) * 2);
		target[0] = '%';
		target[1] = 0;
	}
	if (data.preci && data.spec != 'c')
	{
		p = ft_strdup_bonus(target);
		free(target);
		index->freed = 1;
		target = do_precision(p, data);
		if (p != target)
			free(p);
	}
	return (continue_process1(target, data, index));
}
