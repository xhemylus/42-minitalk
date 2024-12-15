# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abollen <abollen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 14:22:31 by abollen           #+#    #+#              #
#    Updated: 2022/01/20 12:55:13 by abollen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#***** VARIABLES *****#

SERVER = ./server
CLIENT = ./client
HEADER = includes/minitalk.h

SERVER_FILES = server.c server_utils.c utils.c
CLIENT_FILES = client.c client_utils.c utils.c
SERVER_OBJ = ${addprefix ${OBJ_DIR}/,${SERVER_FILES:.c=.o}}
CLIENT_OBJ = ${addprefix ${OBJ_DIR}/,${CLIENT_FILES:.c=.o}}

SERVER_DIR = src/server
CLIENT_DIR = src/client
OBJ_DIR = obj

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes/

#***** RULES *****#

all : ${OBJ_DIR} ${CLIENT} ${SERVER}

${OBJ_DIR}/%.o: ${SERVER_DIR}/%.c ${HEADER}
	@${CC} ${CFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${CLIENT_DIR}/%.c ${HEADER}
	@${CC} ${CFLAGS} -c $< -o $@

${CLIENT} : ${OBJ_DIR} ${CLIENT_OBJ}
	@${CC} ${CFLAGS} -o ${CLIENT} ${CLIENT_OBJ}
	@echo "\033[92m[BUILD] \033[0m${CLIENT} "

${SERVER} : ${OBJ_DIR} ${SERVER_OBJ}
	@${CC} ${CFLAGS} -o ${SERVER} ${SERVER_OBJ}
	@echo "\033[92m[BUILD] \033[0m${SERVER}"

${OBJ_DIR} :
	@mkdir ${OBJ_DIR}
	@echo "\033[92m[BUILD] \033[0m${OBJ_DIR} folder"

clean :
	@rm -rf ${OBJ_DIR}
	@echo "\033[93m[CLEAN]\033[0m ${OBJ_DIR} folder"

fclean : clean
	@rm -f ${CLIENT} ${SERVER}
	@echo "\033[93m[CLEAN]\033[0m ${CLIENT}"
	@echo "\033[93m[CLEAN]\033[0m ${SERVER}"

re : fclean all

.PHONY : all clean fclean re