CC= gcc

CFLAGS= -Wall -Wextra -Werror -I./lib 

NAME1 = checker

NAME2 = push_swap

FILES1= checker visualization

FILES2= push_swap ft_sorting ft_sort_small ft_optimizer

FILES = validation ft_commands ft_operations stack_helper sort_helper

SRC= $(addsuffix .c, $(FILES))

SRC1= $(addsuffix .c, $(FILES1))

SRC2= $(addsuffix .c, $(FILES2))

OBJ= $(addsuffix .o, $(FILES))

OBJ1= $(addsuffix .o, $(FILES1))

OBJ2= $(addsuffix .o, $(FILES2))

NAME= $(NAME1) $(NAME2)

all: $(NAME)

$(NAME1): $(OBJ) $(OBJ1)
	make -C lib
	$(CC) $(CFLAGS) $(OBJ) $(OBJ1) -L./lib -lft -o $@

$(NAME2): $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ2) -L./lib -lft -o $@

$(OBJ):
	$(CC) $(CFLAGS) -c $(SRC)

$(OBJ1):
	$(CC) $(CFLAGS) -c $(SRC1) 

$(OBJ2):
	$(CC) $(CFLAGS) -c $(SRC2) 

clean:
	rm -f *.o
	make clean -C ./lib

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib

re: fclean all

