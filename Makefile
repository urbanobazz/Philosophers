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


BONUS_NAME = philo_bonus
BONUS_OBJDIR = bonus_obj
BONUS_INCLUDE = -I ./bonus/bonus.h
BONUS_OBJS	=	$(SRCS:%.c=$(OBJDIR)/%.o)
BONUS_SRCS	=	bonus/main_bonus.c \
				bonus/routine_bonus.c \
				bonus/utils_bonus.c \
				bonus/monitor_bonus.c \
				bonus/exit_bonus.c \
				bonus/data_init_bonus.c \
				bonus/activities_bonus.c

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)/srcs
	@mkdir -p $(OBJDIR)/srcs/utils

$(OBJDIR)/%.o: %.c
	@$(CC) -o $@ -c $< $(INCLUDE) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(INCLUDE) -o $(NAME)

bonus:$(BONUS_OBJDIR) $(BONUS_NAME)

$(BONUS_OBJDIR):
	@mkdir -p $(OBJDIR)

$(BONUS_OBJDIR)/%.o: %.c
	@$(CC) -o $@ -c $< $(BONUS_INCLUDE) && printf "Compiling: $(notdir $<)\n"

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(BONUS_INCLUDE) -o $(BONUS_NAME)

clean:
	@rm -rf $(OBJDIR)
	@rm -rf $(BONUS_OBJDIR)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
