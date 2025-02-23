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

void	insert_index(t_stack *stack)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < stack->len_a)
	{
		j = 0;
		while (j < stack->len_a)
		{
			if (stack->list[i] > stack->list[j])
				count++;
			j++;
		}
		stack->a[i] = count;
		count = 0;
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

static void	radix_2(t_stack *stack, int bits, int i)
{
	int	j;
	int	len_b;

	j = 0;
	len_b = stack->len_b;
	while (j < len_b)
	{
		if ((((stack->b[0] >> (i + 1)) & 1) == 1) || i == (bits - 1))
			pa(stack, 0);
		else
			rb(stack, 0);
		j++;
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
	insert_index(stack);
	while ((validate_order(stack) == 1 || stack->len_b != 0) && (i != bits))
	{
		j = 0;
		size = stack->len_a;
		while (j < size)
		{
			if ((((stack->a[0] >> i) & 1) == 1))
				ra(stack, 0);
			else
				pb(stack, 0);
			j++;
		}
		radix_2(stack, bits, i);
		i++;
	}
}
