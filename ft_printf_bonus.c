/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:35:29 by mkabissi          #+#    #+#             */
/*   Updated: 2021/12/14 17:59:37 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*traitement_type_bonus(va_list args, char spec, t_index *index)
{
	char	*target;

	if (spec == 'p' || spec == 'x' || spec == 'X')
		index->hex = va_arg(args, unsigned long);
	if (spec == 'c')
		target = c_render_bonus(va_arg(args, int), index);
	else if (spec == 's')
		target = s_render_bonus(va_arg(args, char *));
	else if (spec == 'p')
		target = p_render_bonus(index->hex, "0123456789abcdef");
	else if (spec == 'd' || spec == 'i')
		target = di_render_bonus(va_arg(args, int), index);
	else if (spec == 'u')
		target = u_render_bonus(va_arg(args, unsigned int));
	else if (spec == 'x')
		target = x_render_bonus(index->hex, "0123456789abcdef");
	else if (spec == 'X')
		target = x_render_bonus(index->hex, "0123456789ABCDEF");
	else
	{
		target = (char *)malloc(sizeof(char) * 2);
		target[0] = spec;
		target[1] = 0;
	}
	return (target);
}

char	*get_targcomb(char *input, va_list args, t_index *index, int *count)
{
	char	*target;
	char	*comb;
	char	*p;
	int		targlen;

	p = NULL;
	if (ft_strchr("cspdiuxX%", input[index->i]))
	{
		target = traitement_type_bonus(args, input[index->i], index);
		comb = ft_substr(input, index->start, index->i - index->start + 1);
		p = do_process(comb, target, index);
		if (p && input[index->i] == 'c' && index->nul == 0)
		{
			targlen = ft_strlen_bonus(p);
			ft_change(&p);
			*count += write(1, p, targlen);
			if (p)
				free(p);
		}
		if (index->freed == 0 && target != p)
			free(target);
		if (comb)
			free(comb);
	}
	return (p);
}

char	*trait_bonus(char *input, va_list args, t_index *index, int *count)
{
	char	*comb;
	char	*p;

	p = NULL;
	index->freed = 0;
	index->start = index->i;
	index->specflag = "cspdiuxX%-0123456789.# +";
	while (input[index->i] && ft_strchr(index->specflag, input[index->i]))
	{
		p = get_targcomb(input, args, index, count);
		if (p)
			return (p);
		++index->i;
	}
	if (index->i != index->start)
	{
		comb = ft_substr(input, index->start, index->i - index->start);
		p = do_process(comb, &input[index->i], index);
		if (comb)
			free(comb);
		return (p);
	}
	return (NULL);
}

void	ft_write_input(char *input, va_list args, t_index *index, int *count)
{
	int		fst_count;
	char	*p;

	p = NULL;
	while (input[++index->i])
	{
		if (input[index->i] == '%')
		{
			index->i++;
			fst_count = *count;
			p = trait_bonus((char *)input, args, index, count);
			if (*count != fst_count)
				continue ;
			if (p)
			{
				*count += write(1, p, ft_strlen_bonus(p));
				if (p)
					free(p);
			}
		}
		else
			*count += write(1, &input[index->i], 1);
	}
}

int	ft_printf(const char *input, ...)
{
	int		count;
	t_index	index;
	va_list	args;

	va_start(args, input);
	count = 0;
	index.i = -1;
	ft_write_input((char *)input, args, &index, &count);
	va_end(args);
	return (count);
}
