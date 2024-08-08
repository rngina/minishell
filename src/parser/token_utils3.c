/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:54:27 by rtavabil          #+#    #+#             */
/*   Updated: 2024/08/08 14:48:59 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_quotes(char *s)
{
	int	i;
	int	index;

	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == '\'')
		{
			index = ft_strchrin(&s[i + 1], '\'');
			if (index < 0)
				return (1);
			i = i + index + 2;
		}
		else if (s[i] == '\"')
		{
			index = ft_strchrin(&s[i + 1], '\"');
			if (index < 0)
				return (1);
			i = i + index + 2;
		}
		else
			i++;
	}
	return (0);
}

char	**split_quotes(char *s, int *i, char **res)
{
	int	start;

	if (s[*i] == '\"')
	{
		start = *i;
		*i = ft_strchrin(&s[*i + 1], '\"');
		if (i > 0)
			*res++ = ft_substr(s, start, *i + 2);
		*i = start + *i + 2;
	}
	else if (s[*i] == '\'')
	{
		start = *i;
		*i = ft_strchrin(&s[*i + 1], '\'');
		if (i > 0)
			*res++ = ft_substr(s, start, *i + 2);
		*i = start + *i + 2;
	}
	return (res);
}

char	**split_red(char *s, int *i, char **res)
{
	if (s[*i] == '>')
	{
		if (s[*i + 1] == '>')
		{
			*res++ = ft_substr(s, *i, 2);
			*i = *i + 1;
		}
		else
			*res++ = ft_substr(s, *i, 1);
	}
	else if (s[*i] == '<')
	{
		if (s[*i + 1] == '<')
		{
			*res++ = ft_substr(s, *i, 2);
			*i = *i + 1;
		}
		else
			*res++ = ft_substr(s, *i, 1);
	}
	*i = *i + 1;
	return (res);
}

char	**split_pipe(char *s, int *i, char **res)
{
	*res++ = ft_substr(s, *i, 1);
	*i = *i + 1;
	return (res);
}

char	**split_exp(char *s, int *i, char **res)
{
	int		j;

	j = 1;
	while (s[*i + j])
	{
		if (is_space(s[*i + j]) || is_special(s[*i + j]))
			break ;
		j++;
	}
	*res++ = ft_substr(s, *i, j);
	*i = *i + j;
	return (res);
}
