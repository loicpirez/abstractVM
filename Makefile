##
## Makefile for abstractVM in /home/loicpirez/CLionProjects/abstractVM_2016
## 
## Made by Loïc Pirez
## Login   <loic.pirez@epitech.eu>
## 
## Started on  Thu Jul 13 13:58:08 2017 Loïc Pirez
## Last update Thu Jul 20 13:41:14 2017 Loïc Pirez
##

CC		=	g++

NAME		=	abstractVM

SRCS		=	$(shell cat sources.mk)

OBJS		=	$(SRCS:.cpp=.o)

INCLUDE		=	-I include/

RM		=	rm -f

CXXFLAGS	+=	-W -Wall -pedantic

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

debug:			CXXFLAGS += -g

debug:			all

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.cpp.o:
			$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

.PHONY:			all clean fclean re

