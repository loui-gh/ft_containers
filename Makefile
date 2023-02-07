SRC		= main.cpp

OBJ		= ${SRC:.cpp=.o}

NAME	= ft_vector

CC		= c++

CFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic-errors

RM		= rm -f

.cpp.o:
		${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

all:		${NAME}

${NAME}:	${INC} ${OBJ}
			${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re