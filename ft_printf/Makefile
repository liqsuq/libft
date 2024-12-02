SOURCE := ft_printf.c print_string.c print_number.c
OBJECT := $(SOURCE:.c=.o)
LFTDIR := ..
CFLAGS := -Wall -Wextra -Werror -I$(LFTDIR)

all: $(OBJECT)

clean:
	$(RM) $(OBJECT)

fclean: clean

re: fclean all
