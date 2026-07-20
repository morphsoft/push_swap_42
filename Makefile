NAME        := push_swap
BONUS_NAME  := checker

CC          := cc
CFLAGS      := -Wall -Wextra -Werror

LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a

INCLUDES    := -I. -I$(LIBFT_DIR) -Iutils -Iutils/stack -Iutils/lexer \
               -Iutils/sorting_operations -Iutils/vector_list \
               -Iutils/error_handeling -Ibonus

COMMON_SRCS := utils/parser/parsing.c \
               utils/lexer/bitmask_apply.c \
               utils/lexer/bitmask_checks.c \
               utils/lexer/bitmask_parse.c \
               utils/lexer/bitmask_resolve.c \
               utils/lexer/bitmask_utils.c \
               utils/error_handeling/ft_printerr.c \
               utils/sorting_operations/push.c \
               utils/sorting_operations/push_both.c \
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
               sorting/complex.c \
               sorting/complex_merge.c \
               sorting/lis.c \
               sorting/medium.c \
               sorting/simple.c \
               sorting/small.c \
               sorting/super_small.c \
               utils/disorder_calculator.c/disorder.c \
               utils/vector_list/create_vlist.c \
               utils/vector_list/free_vlist.c \
               utils/vector_list/ft_vlistappend.c \
               utils/vector_list/ft_vlistpop.c \
               utils/vector_list/ft_vlistprint.c \
               utils/vector_list/ft_vlistpush.c \
               utils/vector_list/ft_vlistresize.c \
               utils/vector_list/vlist_iter.c \
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
