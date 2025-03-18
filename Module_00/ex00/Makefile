NAME = megaphone

CC = clang++
CPPFLAGS = -Wall -Werror -Wextra 
RM = rm -rf
SRCS = megaphone.cpp

all: $(NAME)

$(NAME):
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)
fclean : $(RM) $ (NAME)
re:			fclean all

.PHONY:		fclean, all, re