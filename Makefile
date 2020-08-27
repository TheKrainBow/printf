################################################################################
#                               Name of the output                             #
################################################################################
NAME				=	libftprintf.a

################################################################################
#                          Paths of sources and objects                        #
################################################################################
PATH_SRCS			=	srcs
PATH_OBJS			=	objs

################################################################################
#                                 Libft's infos                                #
################################################################################
LIBFT_PATH			=	libft
LIBFT_MAKE			=	Makefile
LIBFT				=	${LIBFT_PATH}/libft.a

################################################################################
#                              Name of sources files                           #
################################################################################
SRCS_BASENAME		=	ft_printf.c				\
						ft_parsing.c			\
						char.c					\
						string.c				\
						number.c				\
						hexa.c					\
						address.c				\
						unsigned.c				\
						convert.c				\
						strchr.c				\
						float_print.c			\
						float.c					\
						float2.c					\
						node.c					\
						float_whole.c

################################################################################
#                             Commands and arguments                           #
################################################################################
RM					=	rm -f
GCC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -I${LIBFT_PATH}

################################################################################
#                         DO NOT MODIFY BELOW THIS POINT                       #
################################################################################
SRCS				=	$(addprefix ${PATH_SRCS}/, ${SRCS_BASENAME})
OBJS				=	$(addprefix ${PATH_OBJS}/, ${SRCS_BASENAME:.c=.o})

$(PATH_OBJS)/%.o:	$(PATH_SRCS)/%.c
					${GCC} ${CFLAGS} -c $< -o $@

$(NAME):			${OBJS} ${LIBFT}
					ar rc ${NAME} ${OBJS}
					ranlib ${NAME}

${LIBFT}:
					make -C ${LIBFT_PATH} -f ${LIBFT_MAKE}
					mv ${LIBFT} ${NAME}

all:				${NAME}

bonus:				${NAME}

clean:
					${RM} ${OBJS} ${BONUSOBJS}
					make -C ${LIBFT_PATH} -f ${LIBFT_MAKE} clean

fclean:				clean
					${RM} ${NAME}
					make -C ${LIBFT_PATH} -f ${LIBFT_MAKE} fclean

re:					fclean all

.PHONY:				all clean fclean re
