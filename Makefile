# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 15:17:18 by tbenz             #+#    #+#              #
#    Updated: 2023/11/16 14:56:05 by tbenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= server
NAME1			= client
NAME_BONUS		= server_bonus
NAME_BONUS1		= client_bonus

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

LIBFT 			= ./libraries/libft/libft.a

CC 				= cc

CFLAGS 			= -Wall -Werror -Wextra -g

REMOVE 			= rm -f

SRCS_DIR		= ./sources/
BONUS_SRCS_DIR	= ./bonus_sources/

SRCSS 			= $(addprefix $(SRCS_DIR),\
					/server/server.c)
OBJS			= $(SRCSS:.c=.o)

SRCSC			= $(addprefix $(SRCS_DIR),\
					client/client.c)
OBJC			= $(SRCSC:.c=.o)

SRCSS_BONUS 	= $(addprefix $(BONUS_SRCS_DIR),\
					server_bonus/server_bonus.c)
OBJBS			= $(SRCSS_BONUS:.c=.o)

SRCSC_BONUS 	= $(addprefix $(BONUS_SRCS_DIR),\
					client_bonus/client_bonus.c)
OBJBC			= $(SRCSC_BONUS:.c=.o)

all:			${LIBFT} ${NAME} ${NAME1}

${NAME}:		${LIBFT} $(OBJS)
				${CC} ${OBJS} ${LIBFT} ${CFLAGS} -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

${NAME1}:		${LIBFT} $(OBJC)
				${CC} ${OBJC} ${LIBFT} ${CFLAGS} -o ${NAME1}
				@echo "$(NAME1): $(GREEN)$(NAME1) was compiled.$(RESET)"
				@echo

bonus:			${LIBFT} ${NAME_BONUS} ${NAME_BONUS1}

${NAME_BONUS}:	${LIBFT} ${OBJBS}
				${CC} ${OBJBS} ${LIBFT} ${CFLAGS} -o ${NAME_BONUS}
				@echo "\n$(NAME_BONUS): $(GREEN)$(NAME_BONUS) was compiled with Bonus.$(RESET)"
				@echo

${NAME_BONUS1}:	${LIBFT} ${OBJBC}
				${CC} ${OBJBC} ${LIBFT} ${CFLAGS} -o ${NAME_BONUS1}
				@echo "\n$(NAME_BONUS1): $(GREEN)$(NAME_BONUS1) was compiled with Bonus.$(RESET)"
				@echo

${LIBFT}:
				@echo
				make all -C libraries/libft

%.o: %.c
				${CC} ${CFLAGS} -c $< -o $@

clean:
				make clean -C libraries/libft
				${REMOVE} ${OBJC} ${OBJS} ${OBJBC} ${OBJBS}
				@echo

fclean:			clean
				${REMOVE} ${NAME} ${NAME1} ${NAME_BONUS} ${NAME_BONUS1}
				make fclean -C libraries/libft
				@echo "${NAME}: ${RED}${NAME}, ${NAME_BONUS} and libft.a were deleted${RESET}"
				@echo

re:				fclean all

rebonus:		fclean ${NAME_BONUS} ${NAME_BONUS1}

.PHONY:			all bonus clean fclean re rebonus
