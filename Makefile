_SRC_ =					\
	ft_parse.c			\
	ft_push_swap.c		\
	ft_stack.c

_CMD_ =					\
	ft_pa.c				\
	ft_pb.c				\
	ft_ra.c				\
	ft_rb.c				\
	ft_rr.c				\
	ft_rra.c			\
	ft_rrb.c			\
	ft_rrr.c			\
	ft_sa.c				\
	ft_sb.c

_UTILS_	=				\
	ft_atoi.c			\
	ft_bsearch.c		\
	ft_isdigit.c		\
	ft_memcpy.c			\
	ft_qsort.c

SRC 		= $(addprefix src/, ${_SRC_})
CMD 		= $(addprefix src/cmd/, ${_CMD_})
UTILS		= $(addprefix src/utils/, ${_UTILS_})

SRC 		+= ${CMD}
SRC			+= ${UTILS}

OBJ			= ${SRC:.c=.o}
DEP			= ${OBJ:.o=.d}

NAME 		= push_swap
INCDIR		= include
CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra -g		# TODO: DELETE -g
CPPFLAGS	= -MMD -I./${INCDIR}

all:		${NAME}

${NAME}:	${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
	${RM} ${DEP} ${OBJ}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

-include ${DEP}