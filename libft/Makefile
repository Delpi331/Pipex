SRCS = exit_perror.c free_array.c ft_putstr_fd.c ft_strchr.c ft_substr.c ft_split.c ft_strcat.c ft_strcpy.c ft_strdup.c ft_strjoin.c ft_strjoin3.c ft_strlen.c ft_strncmp.c ft_strncpy.c ft_strsep.c
OBJS = $(SRCS:.c=.o)
NAME = libft.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
