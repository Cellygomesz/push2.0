/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 02:25:09 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/02/22 06:30:18 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	*list;
	int	len_a;
	int	len_b;
	int	index;

}	t_stack;

int		*create_stack(int ac, char **av);
void	order_sort(t_stack *stack);
void	radix(t_stack *stack);
void	error(int fd);
int		is_number(char **av);
int		validate_stack(t_stack *stack);
int		validate_order(t_stack *stack);

void	sa(int *stack_a, int valid);
void	ra(t_stack *stack, int valid);
void	rra(t_stack	*stack, int valid);
void	pa(t_stack *stack, int valid);

void	sb(int *stack_b, int valid);
void	rb(t_stack *stack, int valid);
void	rrb(t_stack	*stack, int valid);
void	pb(t_stack *stack, int valid);


#endif
