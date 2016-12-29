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
							ft_operators.o\
							solve_quick.o\
							solve_quick_sub.o\
							under3_a.o under3_b.o\
							main_pushswap.o\
							stack_sw.o\
							swap_operations.o swap_operations_sub.o\
							ft_quicksort.o\
							sw_destroy.o deal_sts.o\
							check.o

SRC						=	../src/
ICL						=	../include/
CC						=	gcc
CFLAG					=	-Wall -Wextra -Werror
RM						=	/bin/rm -f

HEADERS					=	$(ICL)main.h $(ICL)swap_base.h
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
get_operators.o			:	$(SRC)get_operators.c $(HEADERS)
stack_sw.o				:	$(SRC)stack_sw.c $(HEADERS)
ft_operators.o			:	$(SRC)ft_operators.c $(HEADERS)
option.o				:	$(SRC)option.c $(HEADERS)
usage.o					:	$(SRC)usage.c $(HEADERS)

solve_quick.o			:	$(SRC)solve_quick.c $(HEADERS)
solve_quick_sub.o		:	$(SRC)solve_quick_sub.c $(HEADERS)
under3_a.o				:	$(SRC)under3_a.c $(HEADERS)
under3_b.o				:	$(SRC)under3_b.c $(HEADERS)
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


