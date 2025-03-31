NAME = ex03

CC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCDIR = sources
OBJDIR = objets

SRCS = main.cpp \
	ClapTrap.cpp \
	ScavTrap.cpp \
	FragTrap.cpp \
	DiamondTrap.cpp
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

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

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@$(CC) $(CXXFLAGS) -c $< -o $@
	@echo "$(CYAN)Compilation de $< -> $@$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@echo "$(YELLOW)🧹 Nettoyage terminé ! 🧹$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)🧼 Nettoyage complet terminé ! 🧼$(RESET)"

re: fclean all

.PHONY: all clean fclean re
