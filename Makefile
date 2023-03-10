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
SFOLDER		=	
SRCS		=	./sources/error.c \
				$(addprefix mandatorypart/map/, ${MAP}) \
				$(addprefix mandatorypart/hook/, ${HOOK}) \
				$(addprefix mandatorypart/ray/, ${RAY}) \
				$(addprefix mandatorypart/utils/, ${UTILS})

NOBONUS		=	mandatorypart/main.c \
				mandatorypart/free/free_map.c \
				mandatorypart/free/free_utils.c \
				mandatorypart/free/free_utils_2.c

BONUS		=	bonuspart/main.c \
				bonuspart/free/free_map.c \
				bonuspart/free/free_utils.c \
				bonuspart/free/free_utils_2.c

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
				@echo Linking ๐
				@${CC} ${FLAGS} ${OBJS} ${INCLUDES} ${LIBRARY} $(NOBONUS) -o $@
				@echo Making โ
				@echo "\033[0;32m-= Ready to play! ๐พ =- \033[0;0m"

$(LIBFT) 	:
				@echo "Make of libft...๐ฅ"
				@make -s -C ./libft

$(MLXGL)	:
				@echo "Make of minilibx 42 Codam...๐ฅ"
				@make -s -C ./MLX42

all			:	$(LIBFT) $(MLXGL) $(NAME)

re			:	fclean all

clean		:
				@echo "Cleaning object... ๐"
				@$(RM) $(OBJS)
				@echo "Cleaning object libft...๐"
				@make -s -C ./libft clean
				@echo "Cleaning object MinilibX 42 Codam...๐"
				@make -s -C ./MLX42 clean

fclean		:	clean
				@$(RM) $(NAME)
				@make -C ./libft fclean
				@make -C ./MLX42 fclean
				@echo "Full clean finish... ๐งน"

bonus		:	$(SRCS) += $(BONUS)

.PHONY		:	${NAME} all clean fclean re bonus
