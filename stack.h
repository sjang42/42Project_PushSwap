/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 23:07:33 by sjang             #+#    #+#             */
/*   Updated: 2016/11/25 23:07:34 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# define TRUE	1
# define FALSE	0

# include <stdlib.h>
# include <unistd.h>

typedef int				t_sdata;

typedef	struct			s_stack_node
{
	t_sdata				data;
	struct s_stack_node	*next;
}						t_stack_node;

typedef struct			s_stack
{
	t_stack_node *head;
	t_stack_node *tail;
}						t_stack;

void					ft_stack_init(t_stack *pstack);
int						ft_stack_isempty(t_stack *pstack);

void					ft_stack_push(t_stack *pstack, t_sdata data);
t_sdata					ft_stack_pop(t_stack *pstack);
t_sdata					ft_stack_peek(t_stack *pstack);

void					ft_stack_destroy(t_stack **pstack);
t_stack					*ft_stack_new(void);
/*
**						stack_sw.c
*/
int						ft_stack_size(t_stack *pstack);
t_sdata					ft_stack_least(t_stack *pstack);
t_sdata					ft_stack_most(t_stack *pstack);
void					ft_stack_display(t_stack *pstack);
void					ft_stack_display_cos(t_stack *a, t_stack *b);
int						ft_stack_where_data(t_stack *ps, t_sdata q);

#endif

