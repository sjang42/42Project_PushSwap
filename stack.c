/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 23:07:28 by sjang             #+#    #+#             */
/*   Updated: 2016/11/25 23:07:29 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*스택의 초기화를 진행한다.*/
/*스택 생성 후 제일 먼저 호출되어야 한다.*/
void	ft_stack_init(t_stack *pstack)
{
	pstack->head = NULL;
	pstack->tail = NULL;
}

t_stack *ft_stack_new(void)
{
	t_stack *newst;

	newst = (t_stack*)malloc(sizeof(t_stack));
	ft_stack_init(newst);
	return (newst);
}

/*스택이 빈 경우 TRUE(1)를, 그렇지 않은 경우 FALSE(0)를 반환한다*/
int		ft_stack_isempty(t_stack *pstack)
{
	if (pstack->head == NULL)
		return (TRUE);
	else
		return (FALSE);
}

/*스택에 데이터를 저장한다. 매개변수 data로 전달된 값을 저장한다*/
void	ft_stack_push(t_stack *pstack, t_sdata data)
{
	t_stack_node *newnode;

	newnode = (t_stack_node*)malloc(sizeof(t_stack_node));
	newnode->data = data;
	newnode->next = pstack->head;
	if (!pstack->head)
		pstack->tail = newnode;
	pstack->head = newnode;
}

/*마지막에 저장된 요소를 삭제한다*/
/*삭제된 데이터는 반환된다*/
/*본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.*/
t_sdata	ft_stack_pop(t_stack *pstack)
{
	t_sdata			ret;
	t_stack_node	*tempnode;

	if (ft_stack_isempty(pstack))
		return (0);
	ret = pstack->head->data;
	tempnode = pstack->head;
	pstack->head = pstack->head->next;
	free(tempnode);
	return (ret);
}

/*마지막에 저장된 요소를 반환하되 삭제하지 않는다*/
/*본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.*/
t_sdata	ft_stack_peek(t_stack *pstack)
{
	if (ft_stack_isempty(pstack))
		return (0);
	return (pstack->head->data);
}

void	ft_stack_destroy(t_stack **pstack)
{
	if (!*pstack)
		return ;
	while (!ft_stack_isempty(*pstack))
		ft_stack_pop(*pstack);
	free(*pstack);
	*pstack = NULL;
}
