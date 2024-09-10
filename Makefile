# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 11:48:58 by nlambert          #+#    #+#              #
#    Updated: 2024/09/10 13:46:12 by nlambert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES	= push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC			=	algorithme.c \
				error.c \
				half_optimisation.c \
				initialisation_cmd.c \
				initialisation.c \
				main.c \
				optimisation.c \
				push_swap.c \
				reverse.c \
				rotate.c \

NAME		=	push_swap

OBJS		=	$(SRC:.c=.o)

LGREEN		= \033[1;32m
MAGENTA		= \033[1;35m
END			= \033[0m

all:			$(NAME)
				@clear
				@echo "${MAGENTA} ____  _  _  ____  _  _    ____  _  _   __   ____   ${END}";
				@echo "${MAGENTA}(  _ \/ )( \/ ___)/ )( \  / ___)/ )( \ / _\ (  _ \  ${END}";
				@echo "${MAGENTA} ) __/) \/ (\___ \) __ (  \___ \\ /\ //    \ ) __/  ${END}";
				@echo "${MAGENTA}(__)  \____/(____/\_)(_/  (____/(_/\_)\_/\_/(__)    ${END}";
				@echo "${MAGENTA}                                                    ${END}";

$(NAME):		$(OBJS)
				$(CC) -o $(NAME) $(OBJS)

clean:
				rm -f $(OBJS)
				@clear
				@echo "${LGREEN} ▄████▄   ██▓    ▓█████ ▄▄▄       ███▄    █ ${END}";
				@echo "${LGREEN}▒██▀ ▀█  ▓██▒    ▓█   ▀▒████▄     ██ ▀█   █ ${END}";
				@echo "${LGREEN}▒▓█    ▄ ▒██░    ▒███  ▒██  ▀█▄  ▓██  ▀█ ██▒${END}";
				@echo "${LGREEN}▒▓▓▄ ▄██▒▒██░    ▒▓█  ▄░██▄▄▄▄██ ▓██▒  ▐▌██▒${END}";
				@echo "${LGREEN}▒ ▓███▀ ░░██████▒░▒████▒▓█   ▓██▒▒██░   ▓██░${END}";
				@echo "${LGREEN}░ ░▒ ▒  ░░ ▒░▓  ░░░ ▒░ ░▒▒   ▓▒█░░ ▒░   ▒ ▒ ${END}";
				@echo "${LGREEN}  ░  ▒   ░ ░ ▒  ░ ░ ░  ░ ▒   ▒▒ ░░ ░░   ░ ▒░${END}";
				@echo "${LGREEN}░          ░ ░      ░    ░   ▒      ░   ░ ░ ${END}";
				@echo "${LGREEN}░ ░          ░  ░   ░  ░     ░  ░         ░ ${END}";
				@echo "${LGREEN}░                                           ${END}";


fclean:
				rm -f $(OBJS) $(NAME)
				@clear
				@echo "${LGREEN} .█████▒▄████▄   ██▓    ▓█████ ▄▄▄       ███▄    █ ${END}";
				@echo "${LGREEN}▓██   ▒▒██▀ ▀█  ▓██▒    ▓█   ▀▒████▄     ██ ▀█   █ ${END}";
				@echo "${LGREEN}▒████ ░▒▓█    ▄ ▒██░    ▒███  ▒██  ▀█▄  ▓██  ▀█ ██▒${END}";
				@echo "${LGREEN}░▓█▒  ░▒▓▓▄ ▄██▒▒██░    ▒▓█  ▄░██▄▄▄▄██ ▓██▒  ▐▌██▒${END}";
				@echo "${LGREEN}░▒█░   ▒ ▓███▀ ░░██████▒░▒████▒▓█   ▓██▒▒██░   ▓██░${END}";
				@echo "${LGREEN} ▒ ░   ░ ░▒ ▒  ░░ ▒░▓  ░░░ ▒░ ░▒▒   ▓▒█░░ ▒░   ▒ ▒ ${END}";
				@echo "${LGREEN} ░       ░  ▒   ░ ░ ▒  ░ ░ ░  ░ ▒   ▒▒ ░░ ░░   ░ ▒░${END}";
				@echo "${LGREEN} ░ ░   ░          ░ ░      ░    ░   ▒      ░   ░ ░ ${END}";
				@echo "${LGREEN}       ░ ░          ░  ░   ░  ░     ░  ░         ░ ${END}";
				@echo "${LGREEN}       ░                                           ${END}";


re: fclean all

.PHONY: all clean fclean re bonus
