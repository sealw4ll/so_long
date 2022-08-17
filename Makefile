SRC		= so_long.c images.c split.c maps.c exit.c movemint.c itoa.c

OBJ		= $(SRC:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra 

NAME	= so_long
PRINTF	= libftprintf.a

all: $(NAME) 

#-fsanitize=address -g3

$(NAME): $(OBJ) a
	$(CC) $(OBJ) $(PRINTF) -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g3 -o $(NAME)
	mv *.o ./objs/

clean:
	mv ./objs/*.o .
	rm -f $(OBJ)

fclean: clean
	rm -f so_long
	rm -f libftprintf.a

a:
	make -C ./printf/

re: fclean $(NAME)