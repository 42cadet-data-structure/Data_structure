NAME = linkedlist

$(NAME) : our_linkedlist.c main.c linkedlist.h
	@$(CC) our_linkedlist.c main.c -o $@

all : $(NAME)

clean :
	@$(RM) $(NAME)

re :
	@make clean
	@make all

.PHONY : clean re