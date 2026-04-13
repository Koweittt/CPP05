NAME		= Form

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

INC_DIR		= inc/
SRC_DIR		= src/
OBJ_DIR		= obj/

SRCS		= src/main.cpp src/Bureaucrat.cpp \
			  src/Form.cpp

OBJS		= $(SRCS:src/%.cpp=obj/%.o)

HEADERS		= -I$(INC_DIR)

$(OBJ_DIR)%.o: src/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compiled successfully!"

clean:
	$(RM) -r $(OBJ_DIR)
	@echo "Object files cleaned!"

fclean: clean
	$(RM) $(NAME)
	@echo "$(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re
