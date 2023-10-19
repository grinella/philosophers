# Nome eseguibile
NAME = philo

# Compiler e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# File sorgente
SRCS = philo.c \
       main.c

# File oggetto generati
OBJS = $(SRCS:.c=.o)

# Compilazione eseguibile
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compilazione da file sorgente in file oggetto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regola per il comando "make all"
all: $(NAME)

# Pulizia dei file oggetto e dell'eseguibile
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

# Ricompilazione
re: fclean all

.PHONY: all clean fclean 
