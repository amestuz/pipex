NAME = libft.a
HEADER = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_strlen.c 	\
		ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strnstr.c	\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_putchar_fd.c \
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_striteri.c

SRC_BONUS = ft_lstnew_bonus.c	\
		ft_lstadd_front_bonus.c	\
		ft_lstsize_bonus.c		\
		ft_lstlast_bonus.c		\
		ft_lstadd_back_bonus.c	\
		ft_lstdelone_bonus.c	\
		ft_lstclear_bonus.c		\
		ft_lstiter_bonus.c		\
		ft_lstmap_bonus.c

SRC_GNL = get_next_line_bonus.c	\
		get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)
# $(info $(OBJ))

OBJ_BONUS = $(SRC_BONUS:.c=.o)
# $(info $(OBJ_BONUS))

OBJ_GNL = $(SRC_GNL:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_GNL)
	ar rcs $(NAME) $(OBJ) $(OBJ_GNL)

$(OBJ): $(SRC) $(HEADER)
	$(CC) $(CFLAGS) -c $(SRC)

$(OBJ_GNL): $(SRC_GNL) $(HEADER)
	$(CC) $(CFLAGS) -c $(SRC_GNL)

bonus: $(OBJ_BONUS) $(OBJ)
	ar rcs $(NAME) $(OBJ_BONUS) $(OBJ) $(OBJ_GNL)

$(OBJ_BONUS): $(SRC_BONUS) $(HEADER)
	$(CC) $(CFLAGS) -c $(SRC_BONUS)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS) $(OBJ_GNL)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus