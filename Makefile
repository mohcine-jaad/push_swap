NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = main_v2.c examiners.c ft_split.c helper.c ft_putstr_fd.c ft_atol.c dynamic_array/clear_array.c dynamic_array/creat_array.c \
	dynamic_array/get_element.c dynamic_array/push_back.c dynamic_array/resize_array.c linked_list/ft_lstadd_back.c \
	linked_list/ft_lstadd_front.c linked_list/ft_lstclear.c linked_list/ft_lstdelone.c linked_list/ft_lstiter.c linked_list/ft_lstlast.c \
	linked_list/ft_lstmap.c linked_list/ft_lstnew.c linked_list/ft_lstsize.c rules/ft_pa.c rules/ft_pb.c rules/ft_ra.c rules/ft_rb.c \
	rules/ft_rr.c rules/ft_rra.c rules/ft_rrb.c rules/ft_rrr.c rules/ft_sa.c rules/ft_sb.c rules/ft_ss.c rules/helpers.c sort.c ft_find_target.c \

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