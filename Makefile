NAME        := push_swap
CC          := cc
CFLAGS      := -Wall -Wextra -Werror

LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a

INCLUDES    := -Iinclude -I$(LIBFT_DIR)

SRCS        := $(shell find src -type f -name '*.c')
OBJS        := $(SRCS:.c=.o)

RM          := rm -f

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) re
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus: all
