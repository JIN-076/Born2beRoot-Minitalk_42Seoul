# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 19:34:57 by jhong             #+#    #+#              #
#    Updated: 2022/02/24 16:30:37 by jhong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FG_GREEN   = \e[32m
FG_LBLUE   = \e[94m
FG_MAGENTA = \e[35m
NO_COLOR   = \e[0m

SERVER = $(addprefix srcs/,	\
	server \
)

CLIENT = $(addprefix srcs/,	\
	client \
)

COMMON = $(addprefix srcs/,	\
	process	\
	put	\
)

SERVER_SRCS = $(addsuffix .c, $(SERVER) $(COMMON))
CLIENT_SRCS = $(addsuffix .c, $(CLIENT) $(COMMON))

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

INCLUDES = -I ./includes/

RM = rm -rf

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_SRCS)
		@$(CC) $(CFLAGS) $^ $(INCLUDES) -o $@
		@printf "${FG_LBLUE}server build success\n${NO_COLOR}"

$(CLIENT) : $(CLIENT_SRCS)
		@$(CC) $(CFLAGS) $^ $(INCLUDES) -o $@
		@printf "${FG_MAGENTA}client build success\n${NO_COLOR}"

clean :
		@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
		@printf "${FG_GREEN}clean success\n${NO_COLOR}"

fclean :
		@$(RM) $(SERVER) $(CLIENT)
		@printf "${FG_GREEN}fclean success\n${NO_COLOR}"

re : fclean all


.PHONY: all clean fclean re
