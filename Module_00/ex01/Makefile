# Nom du programme
NAME = 

# Compilateur et options
CC = clang++
CXXFLAGS = -Wall -Werror -Wextra 

# Dossiers
SRCDIR = sources
OBJDIR = objets

# Fichiers sources et objets
SRCS = 
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Couleurs
CYAN = \033[38;5;45m
PINK = \033[38;5;213m
GREEN = \033[32m
YELLOW = \033[38;5;220m
RESET = \033[0m
BOLD = \033[1m

# Compilation du programme
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BOLD)$(PINK)🎉 Compilation réussie !!! 🎉$(RESET)"

# Compilation des fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@$(CC) $(CXXFLAGS) -c $< -o $@
	@echo "$(CYAN)Compilation de $< -> $@$(RESET)"

# Création du dossier objets si inexistant
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Nettoyage des fichiers objets
clean:
	@rm -rf $(OBJDIR)
	@echo "$(YELLOW)🧹 Nettoyage terminé ! 🧹$(RESET)"

# Nettoyage complet
fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)🧼 Nettoyage complet terminé ! 🧼$(RESET)"

# Recompiler proprement
re: fclean all

.PHONY: all clean fclean re
