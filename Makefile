# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/26 00:17:36 by sjang             #+#    #+#              #
#    Updated: 2016/11/26 00:17:37 by sjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET1					=	checker
TARGET2					=	push_swap

OBJECTS1				=	swap_operations.o swap_operations_sub.o\
							stack.o check.o get_operators.o\
							fill_stack.o\
							add_libft.o\
							checker_main.o ft_read_one.o\
							\
							stack_sw.o sw_solve_min.o\
							\
							solve_quick.o\
							\
							ft_quicksort.o\
							\
							ft_operators.o\
							\
							ftssau_deal.o\
							\
							solve_send.o

SRC						=	./
ICL						=	./
CC						=	gcc
CFLAG					=
RM						=	/bin/rm -f

HEADERS					=	$(ICL)main.h $(ICL)stack.h $(ICL)swap_base.h
LIBFT					=	-L./libft -lft

.PHONY					:	clean fclean re

all						:	$(TARGET1)

$(TARGET1)				:	$(OBJECTS1) $(HEADERS) ./libft/libft.a
							$(CC) $(CFLAG) -o $@ $(OBJECTS1) $(LIBFT)

./libft/libft.a			:
							make -C libft

.c.o					:
							$(CC) $(CFLAG) -c $<

checker_main.o			:	$(SRC)checker_main.c $(HEADERS)
swap_operations.o		:	$(SRC)swap_operations.c $(HEADERS)
swap_operations_sub.o	:	$(SRC)swap_operations_sub.c $(HEADERS)
stack.o					:	$(SRC)stack.c $(HEADERS)
check.o					:	$(SRC)check.c $(HEADERS)
calculator.o			:	$(SRC)calculator.c $(HEADERS)
fill_stack.o			:	$(SRC)fill_stack.c $(HEADERS)
add_libft.o				:	$(SRC)add_libft.c $(HEADERS)
get_operators.o			:	$(SRC)get_operators.c $(HEADERS)
ft_read_one.o			:	$(SRC)ft_read_one.c $(HEADERS)

stack_sw.o				:	$(SRC)stack_sw.c $(HEADERS)
sw_solve_min.o			:	$(SRC)sw_solve_min.c $(HEADERS)

solve_quick.o			:	$(SRC)solve_quick.c $(HEADERS)

ft_quicksort.o			:	$(SRC)ft_quicksort.c $(HEADERS)

ft_operators.o			:	$(SRC)ft_operators.c $(HEADERS)

ftssau_deal.o			:	$(SRC)ftssau_deal.c $(HEADERS)

solve_send.o			:	$(SRC)solve_send.o $(HEADERS)



clean					:
							$(RM) $(OBJECTS1)
fclean					:	clean
							$(RM) $(TARGET1)
re						:	fclean all
