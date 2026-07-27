NAME        := push_swap
BONUS_NAME  := checker

CC          := cc
CFLAGS      := -Wall -Wextra -Werror

LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a

INCLUDES    := -I. -I$(LIBFT_DIR) -Iutils -Iutils/stack -Iutils/lexer \
               -Iutils/sorting_operations \
               -Iutils/error_handling -Ibonus

COMMON_SRCS := utils/parser/parsing.c \
               utils/lexer/bitmask_apply.c \
               utils/lexer/bitmask_checks.c \
               utils/lexer/bitmask_parse.c \
               utils/lexer/bitmask_resolve.c \
               utils/lexer/bitmask_utils.c \
               utils/error_handling/ft_printerr.c \
               utils/sorting_operations/push.c \
               utils/sorting_operations/reverse_rotate.c \
               utils/sorting_operations/reverse_rotate_both.c \
               utils/sorting_operations/rotate.c \
               utils/sorting_operations/rotate_both.c \
               utils/sorting_operations/swap.c \
               utils/sorting_operations/swap_both.c \
               utils/stack/create_stack.c \
               utils/stack/free_stack.c \
               utils/stack/normalize_stack.c \
               utils/stack/stack_stats.c \
               utils/stack/stack_utils.c

SRCS        := main.c \
               sorting/apply_operations.c \
               sorting/apply_operations_b.c \
               sorting/complex.c \
               sorting/complex_merge.c \
               sorting/lis.c \
               sorting/lis_mark.c \
               sorting/medium.c \
               sorting/simple.c \
               sorting/small.c \
               sorting/super_small.c \
               sorting/turn.c \
               sorting/turn_both.c \
               utils/disorder/disorder.c \
               benchmark/create_benchmark.c \
               $(COMMON_SRCS)

BONUS_SRCS  := bonus/checker.c \
               bonus/checker_ops.c \
               bonus/checker_run.c \
               $(COMMON_SRCS)

OBJS        := $(SRCS:.c=.o)
BONUS_OBJS  := $(BONUS_SRCS:.c=.o)

RM          := rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
