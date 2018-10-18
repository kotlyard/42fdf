NAME = fdf

C = gcc

CFLAG = -Wall -Wextra -Werror

LINKS = -lmlx -framework OpenGL -framework AppKit

INC = -I ./includes -I ./libft -I /usr/local/include

LIBDIR = libft

LIBFT = $(LIBDIR)/libft.a

LIBS = -L /usr/local/lib/ -lmlx -L ./libft -lft

SRCDIR = src

SRC = 	main.c \
		parse.c \
		tools.c  \
		list_tools.c \
		math_staff.c \
		mlx_staff.c


OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean

.NOTPARALLEL: all clean fclean

%.o: $(SRCDIR)/%.c
	@$(C) $(CFLAG) -c $< $(INC)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBDIR)
	@mkdir obj/
	@$(C) $(CFLAG) -o $(NAME) $(OBJ) $(LIBS) $(LINKS)
	@mv *.o obj/
	@echo FdF is ready to use.

clean:
	@make clean -C $(LIBDIR)
	@/bin/rm -rf obj/
	@echo Object files have been cleaned.

fclean: clean
	@make fclean -C $(LIBDIR)
	@/bin/rm -f $(NAME)
	@echo FdF has been removed.

re: fclean all
