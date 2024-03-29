# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 20:36:39 by uurbizu-          #+#    #+#              #
#    Updated: 2023/11/05 21:07:43 by uurbizu-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address

MAKE = make

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = inc
LIBFT_PATH = inc/libft

SRC_FILES = $(SRC_DIR)/pipex.c $(SRC_DIR)/utils_pipex.c
#OBJ_FILES = $(SRC_FILES:.c=$(OBJ_DIR)/.o)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o,$(SRC_FILES))

SRC_BONUS_FILES = $(SRC_DIR)/pipex_bonus.c $(SRC_DIR)/utils_pipex.c $(SRC_DIR)/utils_pipex_bonus.c
#OBJ_BONUS_FILES = $(SRC_BONUS_FILES:.c = $(OBJ_DIR)/%c)
OBJ_BONUS_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o,$(SRC_BONUS_FILES))

#$(info SRC $(SRC_FILES)) con esta regla imprimo la vble para ver que hace, como printf
#$(info OBJ $(OBJ_FILES))

LIBFT = $(LIBFT_PATH)/libft.a

NAME = pipex
NAME_BONUS = pipex_bonus

#.SILENT: esto para quitar los @
all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
#	make -C $(LIBFT_PATH) para sustituir la regla del LIBFT
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME): $(GREEN)$(OBJ_DIR) directory was created$(RESET)"
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_PATH) -c -o $@ $<
	@echo "$(NAME): $(GREEN)$@ object file created$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)
	@echo "$(NAME): $(GREEN)$(LIBFT) was created$(RESET)"

bonus: $(OBJ_BONUS_FILES) $(LIBFT) #111$(NAME_BONUS)

#111$(NAME_BONUS): $(OBJ_BONUS_FILES) $(LIBFT)
#1111@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft
	@$(CC) $(CFLAGS) -o $(NAME) $^ -L$(LIBFT_PATH) -lft
	@echo "$(NAME_BONUS): $(GREEN)$(NAME_BONUS) was created$(RESET)"

#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
#	@mkdir -p $(OBJ_DIR)
#	@echo "$(NAME_BONUS): $(GREEN)$(OBJ_DIR) directory was created$(RESET)"
#	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_PATH) -c -o $@ $<
#	@echo "$(NAME_BONUS): $(GREEN)$@ object file created$(RESET)"

#$(LIBFT):
#	@$(MAKE) -C $(LIBFT_PATH)
#	@echo "$(NAME_BONUS): $(GREEN)$(LIBFT) was created$(RESET)"

clean:
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -r $(OBJ_DIR)
	@echo "$(NAME): $(RED)$(OBJ_DIR) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"


fclean: clean
#	@$(MAKE) -C $(LIBFT_PATH) fclean
#	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
#111	@rm $(NAME) $(NAME_BONUS)
	@rm $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all #111 bonus

re_bonus: fclean bonus #regla añadida en el caso 111

.PHONY: all bonus clean fclean re re_bonus #el ultimo PHONY para caso 111
