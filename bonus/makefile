BONUS_NAME		= philo_bonus
CC				=	cc -Wextra -Wall -Werror -g -pthread
BONUS_OBJDIR	= bonus_obj
BONUS_INCLUDE	= -I ./bonus/bonus.h
BONUS_OBJS		=	$(BONUS_SRCS:%.c=$(BONUS_OBJDIR)/%.o)
BONUS_SRCS		=	main_bonus.c \
					routine_bonus.c \
					utils_bonus.c \
					exit_bonus.c \
					data_init_bonus.c \
					activities_bonus.c

all:$(BONUS_OBJDIR) $(BONUS_NAME)

$(BONUS_OBJDIR):
	@mkdir -p $(BONUS_OBJDIR)

$(BONUS_OBJDIR)/%.o: %.c
	@$(CC) -o $@ -c $< $(BONUS_INCLUDE) && printf "Compiling: $(notdir $<)\n"

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(BONUS_INCLUDE) -o $(BONUS_NAME)

clean:
	@rm -rf $(BONUS_OBJDIR)

fclean: clean
	@rm -rf $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
