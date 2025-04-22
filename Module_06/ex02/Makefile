NAME = ex02

CC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
INCLUDES = -Iincludes

SRCDIR = srcs
OBJDIR = objets

SRCS_NAME = main.cpp \
			Base.cpp

OBJS_NAME = $(SRCS_NAME:.cpp=.o)

SRCS        =    $(addprefix $(SRCDIR)/,$(SRCS_NAME))
OBJS        =    $(addprefix $(OBJDIR)/,$(OBJS_NAME))

# Couleurs
CYAN = \033[38;5;45m
PINK = \033[38;5;213m
GREEN = \033[32m
YELLOW = \033[38;5;220m
RESET = \033[0m
BOLD = \033[1m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BOLD)$(PINK)🎉 Compilation réussie !!! 🎉$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(CYAN)Compilation de $< -> $@$(RESET)"

clean:
	@rm -rf $(OBJDIR)
	@echo "$(YELLOW)🧹 Nettoyage terminé ! 🧹$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)🧼 Nettoyage complet terminé ! 🧼$(RESET)"

re: fclean all

.PHONY: all clean fclean re
