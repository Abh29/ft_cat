SRC = src/*.c gnl/*.c main.c

CC = gcc

NAME = ft_cat

FLGS = -Wall -Werror -Wextra

VALGFLGS = --vgdb=full \
		 --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt

FBSIZE = -D BUFFER_SIZE=42

HEADER = ft_cat.h

ARGS = ""

TEST_FILE = ft_cat_tests.sh


all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	@$(CC) $(FLGS) $(FBSIZE) $(SRC) -o $(NAME)

run: $(NAME)
	@./$(NAME) $(ARGS)

clean :
	@rm -f *.o
	@rm -f valgrind-out.txt

fclean: clean
	@rm -f $(NAME)
	@rm -f result.txt result2.txt

re: fclean all

test: $(NAME) $(TEST_FILE)
	bash $(TEST_FILE)

style: $(SRC)
	python3 cpplint.py --extensions=c $(SRC)

cppckeck :
	cppcheck --enable=all --suppress=missingIncludeSystem $(SRC)

debug: $(SRC) $(HEADER)
	@$(CC) $(FLGS) -g $(FBSIZE) $(SRC) -o $(NAME)

valgrind: $(NAME)
	@valgrind $(VALGFLGS) ./$(NAME) $(ARGS)

.PHONY: all clean fclean re test valgrind debug cppcheck style
