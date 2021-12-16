RS = resources/

UT = utils/

BRS = bonus_resources/

BUT = bonus_utils/

BPR = bonus_process/

SRCS = ft_printf.c \
	${RS}ft_itoa.c ${RS}ft_utoa.c ${RS}ft_strlen.c \
	${UT}type_render_csdi.c ${UT}type_render_uxp.c

BONUS_SRCS = ft_printf_bonus.c ${BRS}ft_strcmp_bonus.c \
	${BPR}plus_hash_process.c ${BPR}precision_process.c \
	${BPR}space_process.c ${BPR}width_process.c ${BPR}zero_process.c \
	${BRS}ft_itoa_bonus.c ${BRS}ft_strdup_bonus.c ${BRS}ft_strlen_bonus.c \
	${BRS}ft_strchr_bonus.c ${BRS}ft_strjoin_bonus.c ${BRS}ft_atoi_bonus.c \
	${BRS}ft_utoa_bonus.c ${BRS}ft_memcpy_bonus.c \
	${BUT}auxiliaries_bonus.c ${BUT}get_data_bonus.c ${BRS}ft_strrchr_bonus.c \
	${BRS}ft_substr_bonus.c ${BUT}type_render_csdi_bonus.c \
	${BUT}type_render_uxp_bonus.c ${BPR}process_all_flags.c

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar rc

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

.c.o :
	${CC} ${CFLAGS} -c $< -o $@
	${AR} ${NAME} $@

all : ${NAME}

${NAME} : ${OBJS}

bonus : ${BONUS_OBJS}

clean :
	rm -f ${OBJS} ${BONUS_OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : re fclean clean all bonus
