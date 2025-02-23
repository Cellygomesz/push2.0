/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 02:23:29 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/02/22 06:16:39 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int fd)
{
	ft_putendl_fd("Error", fd);
	exit(1);
}

static void	init_stack(t_stack *stack, char **av)
{
	stack->b = ft_calloc(sizeof(int), stack->len_a);
	stack->a = create_stack(stack->len_a, av);
	stack->len_b = 0;
	stack->index = 0;
}

long	ft_atol(const char *nptr)
{
	long	i;
	long	neg;
	long	temp;

	i = 0;
	neg = 1;
	temp = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		temp = (nptr[i] - '0') + (temp * 10);
		i++;
	}
	temp = temp * neg;
	if (temp >= -2147483648 && temp <= 2147483647)
		return (temp);
	return (temp);
}

int	*create_stack(int ac, char **av)
{
	int	*stack;
	int	i;
	int	j;

	i = 0;
	j = 1;
	stack = malloc(sizeof(int) * (ac + 1));
	if (!stack)
		return (NULL);
	while (--ac >= 0)
	{
		stack[i++] = ft_atol(av[j++]);
	}
	return (stack);
}

int	main(int ac, char **av)
{
	t_stack	stack;

	is_number(av);
	stack.len_a = ac - 1;
	stack.list = create_stack(stack.len_a, av);
	if (!validate_stack(&stack, av))
		return (0);
	if (ac < 3)
		return (0);
	else
	{
		init_stack(&stack, av);
		insert_index(&stack);
		order_sort(&stack);
	}
	free(stack.list);
	free(stack.a);
}
