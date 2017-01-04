# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/27 16:21:00 by sjang             #+#    #+#              #
#    Updated: 2016/12/27 16:21:01 by sjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


TARGET					=	../push_swap

OBJECTS					=	usage.o\
							option.o\
							fill_stack.o\
							fill_stack2.o\
							ft_operators.o\
							ft_op_store.o\
							solve_quick_atob.o\
							solve_quick_btoa.o\
							solve_quick_sub.o solve_quick_sub2.o\
							solve_quick_sub3.o\
							under3_a.o under3_b.o\
							under3_sub.o\
							main_pushswap.o\
							stack_sw.o\
							stack_show.o stack_show_sub.o\
							swap_operations.o swap_operations_sub.o\
							ft_quicksort.o\
							sw_destroy.o deal_sts.o\
							check.o

SRC						=	../src/
ICL						=	../include/
CC						=	gcc
CFLAG					=	-Wall -Wextra -Werror
RM						=	/bin/rm -f

HEADERS					=	$(ICL)main.h
LIBFT					=	-L../libft -lft

.PHONY					:	clean fclean re

all						:	$(TARGET)

$(TARGET)				:	$(OBJECTS) $(HEADERS) ../libft/libft.a
							$(CC) $(CFLAG) -o $@ $(OBJECTS) $(LIBFT)

%.o						:	$(SRC)%.c
							$(CC) -c $(CFLAG) $<

main_checker.o			:	$(SRC)main_checker.c $(HEADERS)
swap_operations.o		:	$(SRC)swap_operations.c $(HEADERS)
swap_operations_sub.o	:	$(SRC)swap_operations_sub.c $(HEADERS)
check.o					:	$(SRC)check.c $(HEADERS)
fill_stack.o			:	$(SRC)fill_stack.c $(HEADERS)
fill_stack2.o			:	$(SRC)fill_stack2.c $(HEADERS)
get_operators.o			:	$(SRC)get_operators.c $(HEADERS)
stack_sw.o				:	$(SRC)stack_sw.c $(HEADERS)
stack_show.o			:	$(SRC)stack_show.c $(HEADERS)
stack_show_sub.o		:	$(SRC)stack_show_sub.c $(HEADERS)

ft_operators.o			:	$(SRC)ft_operators.c $(HEADERS)
ft_op_store.o			:	$(SRC)ft_op_store.c $(HEADERS)
option.o				:	$(SRC)option.c $(HEADERS)
usage.o					:	$(SRC)usage.c $(HEADERS)

solve_quick_atob.o		:	$(SRC)solve_quick_atob.c $(HEADERS)
solve_quick_btoa.o		:	$(SRC)solve_quick_btoa.c $(HEADERS)
solve_quick_sub.o		:	$(SRC)solve_quick_sub.c $(HEADERS)
solve_quick_sub2.o		:	$(SRC)solve_quick_sub2.c $(HEADERS)
solve_quick_sub3.o		:	$(SRC)solve_quick_sub3.c $(HEADERS)

under3_a.o				:	$(SRC)under3_a.c $(HEADERS)
under3_b.o				:	$(SRC)under3_b.c $(HEADERS)
under3_sub.o			:	$(SRC)under3_sub.c $(HEADERS)
ft_quicksort.o			:	$(SRC)ft_quicksort.c $(HEADERS)

stack_sw.o				:	$(SRC)stack_sw.c $(HEADERS)
sw_destroy.o			:	$(SRC)sw_destroy.c $(HEADERS)
deal_sts.o				:	$(SRC)deal_sts.c $(HEADERS)
check.o					:	$(SRC)check.c $(HEADERS)

clean					:
							$(RM) $(OBJECTS)
fclean					:	clean
							$(RM) $(TARGET)
re						:	fclean all


