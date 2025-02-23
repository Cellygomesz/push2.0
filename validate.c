/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 02:36:10 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/02/22 07:28:49 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		if (av[i][0] == '\0')
			error(2);
		if (av[i][j] == '+' || av[i][j] == '-')
		{
			if (!ft_isdigit(av[i][++j]))
				error(2);
			j++;
		}
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				error(2);
			j++;
		}
	}
	return (0);
}

static int	validate_duplicate(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->len_a)
	{
		j = i + 1;
		while (j < stack->len_a)
		{
			if (stack->list[i] == stack->list[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_order(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->len_a)
	{
		if (stack->list[i - 1] > stack->list[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_size(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atol(av[i]) < -2147483648 || ft_atol(av[i]) > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

int	validate_stack(t_stack *stack, char **av)
{
	if (check_size(av) == 1)
	{
		free(stack->list);
		error(2);
	}
	if (validate_duplicate(stack))
	{
		free(stack->list);
		error(2);
	}
	if (!validate_order(stack))
	{
		free(stack->list);
		return (0);
	}
	return (1);
}
