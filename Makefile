# Vars
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Executable file name
PS = push_swap

# Dirs
SRCDIR = src
OBJDIR = obj

SRC = do_stack.c free_funcs.c ft_split.c lst_funcs.c main.c pa_pb.c push_swap_funcs.c push_swap.c ra_rb_rr.c rra_rrb_rrr.c sa_sb_ss.c set_stack.c sorting.c utils.c get_top_funcs.c
OBJS = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
SRCS = $(addprefix $(SRCDIR)/,$(SRC))

# Rules of files
all: $(PS)

# Executable build rules (explicit)
$(PS): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PS)

# Build the object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rules of actions
clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(PS)

re: fclean all

.PHONY: all clean fclean re