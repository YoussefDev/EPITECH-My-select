##
## Makefile for my_select in /home/sayyou_y/rendu/PSU-System-Unix/PSU_2014_my_select
## 
## Made by Youssef Sayyouri
## Login   <sayyou_y@epitech.net>
## 
## Started on  Tue Dec 16 11:46:07 2014 Youssef Sayyouri
## Last update Sun Jan 11 20:56:27 2015 Youssef Sayyouri
##

SRCS	= main.c	\
	  my_func.c	\
	  list_func.c	\
	  term_opt.c	\
	  list_control.c\

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I.

NAME	= my_select

OBJS	= $(SRCS:.c=.o)

all:	 $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) -lncurses $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean flcean re
