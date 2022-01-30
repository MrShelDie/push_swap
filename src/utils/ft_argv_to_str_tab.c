/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_to_str_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:38:28 by gannemar          #+#    #+#             */
/*   Updated: 2022/01/30 17:38:51 by gannemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_str_tab_len(char **str_tab)
{
	int	i;

	i = -1;
	while (str_tab[++i])
		;
	return (i);
}

static char	**ft_str_tab_join(
	t_arg_tab *arg_tab, char **str_tab, int str_tab_size)
{
	char	**new_str_tab;
	int		total_size;
	int		i;

	total_size = arg_tab->argc + str_tab_size;
	new_str_tab = (char **)malloc(sizeof(char *) * total_size);
	if (!new_str_tab)
		return (NULL);
	i = -1;
	while (++i < arg_tab->argc)
		new_str_tab[i] = arg_tab->argv[i];
	i = -1;
	while (++i < str_tab_size)
		new_str_tab[arg_tab->argc + i] = str_tab[i];
	if (arg_tab->argv)
		free(arg_tab->argv);
	arg_tab->argv = new_str_tab;
	arg_tab->argc = total_size;
	return (arg_tab->argv);
}

static void	ft_free_str_tab(char **str_tab)
{
	int	i;

	i = -1;
	while (str_tab[++i])
		free(str_tab[i]);
	free(str_tab);
}

char	**ft_argv_to_str_tab(int argc, char **argv, t_arg_tab *arg_tab)
{
	char	**temp;
	int		temp_size;
	int		i;

	i = -1;
	while (++i < argc)
	{
		temp = ft_split(argv[i], ' ');
		if (!temp)
			return (NULL);
		temp_size = ft_get_str_tab_len(temp);
		if (temp_size == 0 || !ft_str_tab_join(arg_tab, temp, temp_size))
		{
			ft_free_str_tab(temp);
			arg_tab->argv = NULL;
			return (NULL);
		}
		free(temp);
	}
	return (arg_tab->argv);
}
