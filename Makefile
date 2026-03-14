NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

COMMON_SRCS = push.c swap.c rotate.c reverse_rotate.c \
				check_args.c find_tools.c indexing.c \
				lst_utils.c sort.c split.c stack_init.c \
				utils_parse.c
COMMON_OBJS = $(COMMON_SRCS:.c=.o)

MANDATORY_SRCS = push_swap.c main.c
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)

BONUS_SRCS = bonus/checker.c bonus/checker_utils.c bonus/ft_strcmp.c bonus/get_next_line.c bonus/get_next_line_utils.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MANDATORY_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(MANDATORY_OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c push_swap.h bonus/checker.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	rm -rf $(COMMON_OBJS) $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus