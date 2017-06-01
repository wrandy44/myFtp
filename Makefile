##
## Makefile for azd in /home/debrau_c/bin/new_repo
## 
## Made by debrau_c
## Login   <debrau_c@epitech.net>
## 
## Started on  Fri Apr 29 21:12:18 2016 debrau_c
## Last update Sun May 21 11:10:38 2017 debrau_c
##

SRC	= srcs/main.c		\
	  srcs/main_checker.c	\
	  srcs/client.c		\
	  srcs/clientext.c	\
	  srcs/check_path.c	\
	  srcs/my_str.c		\
	  srcs/my_strext.c	\
	  srcs/tab.c		\
	  srcs/my_socket.c	\
	  srcs/my_socketext.c	\
	  srcs/ftp_func_gest.c	\
	  srcs/crlf.c		\
	  srcs/funcs/list.c	\
	  srcs/funcs/syst.c	\
	  srcs/funcs/retr.c	\
	  srcs/funcs/stor.c	\
	  srcs/funcs/cdup.c	\
	  srcs/funcs/help.c	\
	  srcs/funcs/quit.c	\
	  srcs/funcs/noop.c	\
	  srcs/funcs/pasv.c	\
	  srcs/funcs/port.c	\
	  srcs/funcs/cwd.c	\
	  srcs/funcs/dele.c	\
	  srcs/funcs/pwd.c	\
	  srcs/funcs/mkd.c	\

NAME	= server

OBJ	= $(SRC:.c=.o)

CC	= gcc

RM	= rm -rf

CFLAGS	= -Iinc/	\
	  -W		\
	  -Wextra	\
	  -Wall		\
	  -ansi		\
	  -pedantic	\
	  -std=gnu99	\
	  -Werror	\
	  -g

$(NAME):	$(OBJ)
	@echo [CC] $@
	@$(CC) -o $(NAME) $(OBJ) -lpthread

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	re fclean all clean
