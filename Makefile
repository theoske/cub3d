NAME		=	cub3D
LIBFT		=	libft.a
MLXGL		=	libmlx42.a
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra ${F_EXTRA}
F_EXTRA		=	-g -fsanitize=address
LIBRARY		=	./libft/libft.a ./MLX42/libmlx42.a  ${LIB_LINUX}
LIB_LINUX	=	-ldl -lglfw -pthread -lm ${LIB_MAC}
LIB_MAC		=	-L "/Users/${USER}/.brew/opt/glfw/lib/"
INCLUDE		=	-I./include -I./libft -I./MLX42/include
SFOLDER		=	./srcs/
SRCS		=	error.c \
				$(addprefix map/, ${MAP}) \
				$(addprefix hook/, ${HOOK}) \
				$(addprefix free/, ${FREE}) \
				$(addprefix ray/, ${RAY}) \
				$(addprefix utils/, ${UTILS})

NOBONUS		=	main.c

BONUS		=	../Bonus/main.c

HOOK		=	hook.c
MAP			=	map.c \
				import_param.c \
				import_map.c
FREE		=	free_map.c \
				free_utils.c \
				free_utils_2.c
UTILS		=	ft_get_struct.c \
				ft_file_exist.c \
				ft_file_name.c \
				ft_max.c
RAY			=	ft_sum_ray.c \
				ft_draw.c
OBJS		=	$(addprefix ${SFOLDER}, ${SRCS:.c=.o})
RM			=	rm -rf

.c.o	:
			@$(CC) $(FLAGS) -c $(HEADER) $< $ -o ${<:.c=.o}

$(NAME)		:	${LIBFT} ${MLXGL} $(OBJS)
				@echo Linking 🔗
				@${CC} ${FLAGS} ${OBJS} ${INCLUDES} ${LIBRARY} -o $@
				@echo Making ⚒
				@echo "\033[0;32m-= Ready to play! 👾 =- \033[0;0m"

$(LIBFT) 	:
				@echo "Make of libft...🔥"
				@make -s -C ./libft

$(MLXGL)	:
				@echo "Make of minilibx 42 Codam...🔥"
				@make -s -C ./MLX42

all			:	$(LIBFT) $(MLXGL) $(NAME)

re			:	fclean all

clean		:
				@echo "Cleaning object... 🗑"
				@$(RM) $(OBJS)
				@echo "Cleaning object libft...🗑"
				@make -s -C ./libft clean
				@echo "Cleaning object MinilibX 42 Codam...🗑"
				@make -s -C ./MLX42 clean

fclean		:	clean
				@$(RM) $(NAME)
				@make -C ./libft fclean
				@make -C ./MLX42 fclean
				@echo "Full clean finish... 🧹"

bonus		:	$(SRCS) += $(BONUS)

.PHONY		:	${NAME} all clean fclean re bonus
