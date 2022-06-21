
FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

INC = Mandatory/so_long.h Mandatory/gnl/get_next_line.h

B_INC = Bonus/so_long_bonus.h Bonus/gnl/get_next_line.h

SRC_FILES = so_long.c map_checker.c help.c play.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c



NAME = so_long
NAMEB = so_long_bonus


SRC = $(addprefix Mandatory/, $(SRC_FILES))
O_SRC = $(SRC:.c=.o)



B_SRC_FILES = Bonus/so_long_bonus.c Bonus/map_checker_bonus.c Bonus/help_bonus.c \
			Bonus/play_bonus.c Bonus/update_bonus.c Bonus/ft_printf.c \
			Bonus/gnl/get_next_line.c Bonus/gnl/get_next_line_utils.c

BO_SRC = $(B_SRC_FILES:.c=.o)



all : $(NAME)


$(NAME): $(O_SRC) $(INC)
	cc $(FLAGS) $(O_SRC)  -o $(NAME)
	@echo " \n\
			███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗ \n\
			██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝ \n\
			███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗ \n\
			╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║ \n\
			███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝ \n\
			╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ "

%.o   : %.c $(INC) $(B_INC)
	gcc -Wall -Wextra -Werror -c $< -o $@

bonus : $(NAMEB)

$(NAMEB): $(BO_SRC) $(B_INC) 
	cc $(FLAGS) $(B_SRC) $(BO_SRC) -o so_long_bonus

	@echo " \n\
			███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗         ██████╗  ██████╗ ███╗   ██╗██╗   ██╗███████╗ \n\
			██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝         ██╔══██╗██╔═══██╗████╗  ██║██║   ██║██╔════╝ \n\
			███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗        ██████╔╝██║   ██║██╔██╗ ██║██║   ██║███████╗ \n\
			╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║        ██╔══██╗██║   ██║██║╚██╗██║██║   ██║╚════██║ \n\
			███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝███████╗██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝███████║ \n\
			╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝╚═════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝ "

clean:
	rm -rf  $(BO_SRC) 
	rm -rf $(O_SRC)

fclean: clean
	rm -rf $(NAME) 
	rm -rf $(NAMEB)

re: fclean all

.PHONY: all clean fclean bonus re