NAME	=	philo
CC		=	cc -Wextra -Wall -Werror -g -pthread
INCLUDE	=	-I ./include
OBJDIR	=	obj
OBJS	=	$(SRCS:%.c=$(OBJDIR)/%.o)
SRCS	=	srcs/main.c \
			srcs/exit.c \
			srcs/activities.c \
			srcs/philo_init.c \
			srcs/data_init.c \
			srcs/monitor.c \
			srcs/utils/utils.c

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)/srcs
	@mkdir -p $(OBJDIR)/srcs/utils

$(OBJDIR)/%.o: %.c
	@$(CC) -o $@ -c $< $(INCLUDE) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(INCLUDE) -o $(NAME)


bonus:
	@make -C ./bonus

clean:
	@rm -rf $(OBJDIR)
	@make clean -C ./bonus

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./bonus

re: fclean all

.PHONY: all clean fclean re bonus
