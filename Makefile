NAME = bsq
CC = cc
CFGLAS = -Wextra -Wall -Werror
SRC = main.c first_line.c functions.c solve.c utils.c validate.c
OBJ = $(SRC:.c=.o)
INCLUDES = c_minded.h
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFGLAS) $(OBJ) -o $(NAME)

$(OBJ) : $(INCLUDES)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all
