# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/26 18:15:36 by sjang             #+#    #+#              #
#    Updated: 2016/12/26 18:15:37 by sjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET					=	../checker

OBJECTS					=	usage.o\
							option.o\
							fill_stack.o\
							get_operators.o\
							check.o\
							ft_operators.o\
							ft_op_store.o\
							main_checker.o\
							stack_sw.o\
							stack_show.o stack_show_sub.o\
							swap_operations.o swap_operations_sub.o\
							sw_destroy.o deal_sts.o\
							ft_quicksort.o\
							under3_sub.o

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
ft_op_store.o			:	$(SRC)ft_op_store.c $(HEADERS)
stack_sw.o				:	$(SRC)stack_sw.c $(HEADERS)
ft_operators.o			:	$(SRC)ft_operators.c $(HEADERS)
get_operators.o			:	$(SRC)get_operators.c $(HEADERS)
option.o				:	$(SRC)option.c $(HEADERS)
usage.o					:	$(SRC)usage.c $(HEADERS)

stack_sw.o				:	$(SRC)stack_sw.c $(HEADERS)
stack_show.o			:	$(SRC)stack_show.c $(HEADERS)
stack_show_sub.o		:	$(SRC)stack_show_sub.c $(HEADERS)

sw_destroy.o			:	$(SRC)sw_destroy.c $(HEADERS)
deal_sts.o				:	$(SRC)deal_sts.c $(HEADERS)
ft_quicksort.o			:	$(SRC)ft_quicksort.c $(HEADERS)


clean					:
							$(RM) $(OBJECTS)
fclean					:	clean
							$(RM) $(TARGET)
re						:	fclean all

