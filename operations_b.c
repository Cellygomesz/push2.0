/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 03:54:36 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/02/22 06:22:51 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(int *stack_b, int valid)
{
	int	aux;

	aux = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = aux;
	if (valid == 0)
		ft_putendl_fd("sb", 1);
}

void	rb(t_stack *stack, int valid)
{
	int	aux;
	int	min;

	min = 0;
	aux = stack->b[0];
	while (++min < stack->len_b)
		stack->b[min - 1] = stack->b[min];
	stack->b[min - 1] = aux;
	if (valid == 0)
		ft_putendl_fd("rb", 1);
}

void	rrb(t_stack	*stack, int valid)
{
	int	aux;
	int	max;

	max = stack->len_a - 1;
	aux = stack->b[max];
	while (--max >= 0)
		stack->b[max + 1] = stack->b[max];
	stack->b[0] = aux;
	if (valid == 0)
		ft_putendl_fd("rrb", 1);
}

void	pb(t_stack *stack, int valid)
{
	int	i;

	if (stack->len_a == 0)
		return ;
	i = stack->len_b + 1;
	while (i-- > 0)
		stack->b[i] = stack->b[i - 1];
	stack->b[0] = stack->a[0];
	i = 0;
	while (i++ <= stack->len_a)
		stack->a[i - 1] = stack->a[i];
	stack->len_a--;
	stack->len_b++;
	if (valid == 0)
		ft_putendl_fd("pb", 1);
}
