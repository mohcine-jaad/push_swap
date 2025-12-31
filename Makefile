NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = main_v2.c examiners.c ft_split.c helper.c ft_putstr_fd.c ft_atol.c dynamic_array/clear_array.c dynamic_array/creat_array.c \
	dynamic_array/get_element.c dynamic_array/push_back.c dynamic_array/resize_array.c linked_list/ft_lstadd_back.c \
	linked_list/ft_lstadd_front.c linked_list/ft_lstclear.c linked_list/ft_lstdelone.c linked_list/ft_lstiter.c linked_list/ft_lstlast.c \
	linked_list/ft_lstmap.c linked_list/ft_lstnew.c linked_list/ft_lstsize.c

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all