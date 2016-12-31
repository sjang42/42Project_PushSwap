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

MAKE1					=	./libft
MAKE2					=	./Checker
MAKE3					=	./PushSwap

CLEAN					=	make clean -C
FCLEAN					=	make fclean -C

ifdef ALLOCWRAP
	LDFLAGS += $(HOME)/lib/alloc_wrap.c -ldl
endif 

.PHONY					:	clean fclean re

all						:
							make -C $(MAKE1)
							make -C $(MAKE2)
							make -C $(MAKE3)

clean					:
							$(CLEAN) $(MAKE1)
							$(CLEAN) $(MAKE2)
							$(CLEAN) $(MAKE3)

fclean					:	clean
							$(FCLEAN) $(MAKE1)
							$(FCLEAN) $(MAKE2)
							$(FCLEAN) $(MAKE3)

re						:	fclean all
