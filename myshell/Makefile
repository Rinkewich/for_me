NAME	=	minishell
CC		=	gcc
CFLAGS	=	
INCLUDE	=	-I includes

LIBFTNAME	=	libft.a

OBJDIR	=	obj
SRCDIR	=	src
BUILTINS	=	src/builtins
ENV		=	src/env
INIT	=	src/init
SET_UNSET	= src/set_unset

HEADERS	=	includes/minishell.h includes/libft.h	includes/hed.h

LIBFTPATH	=	libft

SRC		=	main.c		env_find_val.c	init_plite.c\
			init_shlvl.c	export_env.c	unset_env.c

OBJ		=	$(SRC:%.c=$(OBJDIR)/%.o)

.PHONY	:	all clean fclean re

all			:	$(NAME)
	@make -C ${LIBFTPATH}

$(OBJDIR)	:
	mkdir $(OBJDIR)

$(NAME)		:	$(OBJDIR) $(OBJ)
	make -C ${LIBFTPATH}
	$(CC) $(CFLAGS) -lreadline $(OBJ) ${LIBFTPATH}/${LIBFTNAME} -o $(NAME)

$(OBJDIR)/%.o	:	%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)/%.o	:	$(ENV)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)/%.o	:	$(INIT)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)/%.o	:	$(SET_UNSET)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
clean	:
	make -C ${LIBFTPATH} clean
	rm -d -f -r $(OBJDIR)

fclean	:	clean
	make -C ${LIBFTPATH} fclean
	rm -f $(NAME)

re		: fclean all
