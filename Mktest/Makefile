
TARGET					=	../mktest

OBJECTS					=	make_test.o

SRC						=	./
ICL						=	../include/
CC						=	gcc
CFLAG					=	-Wall -Wextra -Werror
RM						=	/bin/rm -f

HEADERS					=
LIBFT					=	-L../libft -lft

.PHONY					:	clean fclean re

all						:	$(TARGET)

$(TARGET)				:	$(OBJECTS) $(HEADERS) ../libft/libft.a
							$(CC) $(CFLAG) -o $@ $(OBJECTS) $(LIBFT)

%.o						:	$(SRC)%.c
							$(CC) -c $(CFLAG) $<
make_test.o				:	$(SRC)make_test.c $(HEADERS)

clean					:
							$(RM) $(OBJECTS)
fclean					:	clean
							$(RM) $(TARGET)
re						:	fclean all
