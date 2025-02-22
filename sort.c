/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 03:56:21 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/02/22 06:27:14 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void easy_op(char *op, t_stack *stack)
{
	if (ft_strncmp(op, "ra", 2) == 0)
	{
		ra(stack, 0);
		stack->index--;
	}
	else if (ft_strncmp(op, "rra", 3) == 0)
	{
		rra(stack, 0);
		stack->index++;
	}
	else if (ft_strncmp(op, "pa", 2) == 0)
	{
		pa(stack, 0);
		pa(stack, 0);
	}
}

static int search_min(t_stack *stack)
{
	int	min;
	int	i;

	min = stack->a[0];
	i = 1;
	while (i < stack->len_a)
	{
		if (stack->a[i] < min)
		{
			min = stack->a[i];
			stack->index = i;
		}
		i++;
	}
	return (min);
}

static void	sort_3(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] \
		&& stack->a[0] < stack->a[2])
			sa(stack->a, 0);
		else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] \
		&& stack->a[0] > stack->a[2])
			rra(stack, 0);
		else if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2] \
		&& stack->a[1] < stack->a[2])
			ra(stack, 0);
		else if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2] \
		&& stack->a[1] > stack->a[2])
		{
			sa(stack->a, 0);
			rra(stack, 0);
		}
		else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] \
		&& stack->a[2] > stack->a[0])
		{
			rra(stack, 0);
			sa(stack->a, 0);
		}
}

static void	sort_5(t_stack *stack)
{
	int	small;

	while (stack->len_a > 3)
	{
		small = search_min(stack);
		if (stack->a[0] != small)
		{
			while (stack->index > 0)
			{
				if (stack->a[0] == small || stack->index >= 5)
					break ;
				if (stack->index <= 2 && stack->index > 0)
					easy_op("ra", stack);
				else
					easy_op("rra", stack);
				if (stack->a[0] == small)
					break ;
			}
		}
		pb(stack, 0);
	}
	sort_3(stack);
	easy_op("pa", stack);
}


void	order_sort(t_stack *stack)
{
	if (stack->len_a == 2)
		sa(stack->a, 0);
	else if (stack->len_a == 3)
		sort_3(stack);
	else if (stack->len_a <= 5)
		sort_5(stack);
	else
		radix(stack);
}
