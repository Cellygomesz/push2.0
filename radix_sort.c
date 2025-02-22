/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 05:25:56 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/02/22 07:56:25 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_index(t_stack *stack)

{
	int	i;
	int	j;

	i = 0;
	while (i < stack->len_a)
	{
		j = 0;
		while (j < stack->len_a)
		{
			if (stack->a[i] == stack->list[j])
			{
				stack->list[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

static int	bits_to_op(t_stack *stack)

{
	int	size;
	int	bits;

	size = stack->len_a;
	bits = 0;
	while ((1 << bits) < size)
		bits++;
	return (bits);
}

// nao esta ordenando corretamente
static void	sort_list(int len, int *stack)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (++i < len)
	{
		j = -1;
		while (++j < len -1)
		{
			if (stack[i] > stack[j + 1])
			{
				temp = stack[j];
				stack[j] = stack[j + 1];
				stack[j + 1] = temp;
			}
		}
	}
}

void	radix(t_stack *stack)
{
	int	i;
	int	j;
	int	size;
	int	bits;

	bits = bits_to_op(stack);
	i = 0;
	size = stack->len_a;
	sort_list(stack->len_a, stack->list);
	insert_index(stack);
	while (validate_order(stack) != 1 && i != bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((stack->a[0] >> i) & 1) == 1))
				ra(stack, 0);
			else
				pb(stack, 0);
			j++;
		}
		while (stack->len_b > 0)
			pa(stack, 0);
		i++;
	}
}
