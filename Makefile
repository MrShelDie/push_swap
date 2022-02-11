_PUSH_SWAP_ =				\
	ft_push_swap.c			\
	ft_restore_stack_a.c	\
	ft_set_all_ways.c		\
	ft_set_all_score.c		\
	ft_small_sort.c			\
	ft_sort.c				\
	ft_throw_elem_to_b.c	\

_GENERAL_ =					\
	ft_is_sorted.c			\
	ft_parse.c				\
	ft_push_swap_init.c		\
	ft_stack.c				\

_CMD_ =						\
	ft_pa.c					\
	ft_pb.c					\
	ft_ra.c					\
	ft_rb.c					\
	ft_rr.c					\
	ft_rra.c				\
	ft_rrb.c				\
	ft_rrr.c				\
	ft_sa.c					\
	ft_sb.c

_ROTATE_ =						\
	ft_ra_rr.c					\
	ft_ra_rrb.c					\
	ft_rb_rr.c					\
	ft_rra_rb.c					\
	ft_rra_rrr.c				\
	ft_rrb_rrr.c

_SET_WAY_SCORE_ =				\
	ft_set_ra_rr_score.c		\
	ft_set_ra_rrb_score.c		\
	ft_set_rb_rr_score.c		\
	ft_set_rra_rb_score.c		\
	ft_set_rra_rrr_score.c		\
	ft_set_rrb_rrr_score.c

_UTILS_	=						\
	ft_argv_to_str_tab.c		\
	ft_atoi.c					\
	ft_bsearch.c				\
	ft_isdigit.c				\
	ft_memcpy.c					\
	ft_qsort.c					\
	ft_split.c					\
	ft_strlcpy.c				\
	ft_strlen.c					\
	ft_strncmp.c

_BONUS_ =						\
	ft_checker_bonus.c			\
	get_next_line_bonus.c		\
	get_next_line_utils_bonus.c

PUSH_SWAP 		= ${addprefix src/, ${_PUSH_SWAP_}}
GENERAL			= ${addprefix src/, ${_GENERAL_}}
CMD 			= ${addprefix src/cmd/, ${_CMD_}}
ROTATE			= ${addprefix src/rotate/, ${_ROTATE_}}
SET_WAY_SCORE	= ${addprefix src/set_way_score/, ${_SET_WAY_SCORE_}}
UTILS			= ${addprefix src/utils/, ${_UTILS_}}

BONUS			= ${addprefix src/bonus/, ${_BONUS_}}

PUSH_SWAP 		+= ${GENERAL}
PUSH_SWAP 		+= ${CMD}
PUSH_SWAP		+= ${ROTATE}
PUSH_SWAP		+= ${SET_WAY_SCORE}
PUSH_SWAP		+= ${UTILS}

BONUS			+= ${GENERAL}
BONUS 			+= ${CMD}
BONUS			+= ${ROTATE}
BONUS			+= ${UTILS}

OBJ				= ${PUSH_SWAP:.c=.o}
BONUS_OBJ		= ${BONUS:.c=.o}

DEP				= ${OBJ:.o=.d}
BONUS_DEP		= ${BONUS_OBJ:.o=.d}

NAME 			= push_swap
BONUS_NAME		= checker
INCDIR			= include
CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra
CPPFLAGS		= -MMD -I./${INCDIR}

all:			${NAME}

${NAME}:		${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

bonus:			${BONUS_NAME}

${BONUS_NAME}: ${BONUS_OBJ}
	${CC} ${CFLAGS} ${BONUS_OBJ} -o ${BONUS_NAME}

clean:
	${RM} ${DEP} ${BONUS_DEP} ${OBJ} ${BONUS_OBJ}

fclean:			clean
	${RM} ${NAME} ${BONUS_NAME}

re:			fclean all

.PHONY:		all clean fclean re

-include ${DEP}
-include ${BONUS_DEP}
