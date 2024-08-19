TARGET = mega_sena

SRCS = main.c src/hash_table.c src/file_reader.c src/stats.c src/concurso.c

HEADERS = src/headers/hash_table.h src/headers/file_reader.h src/headers/stats.h src/headers/concurso.h

CC = gcc

CFLAGS = -Wall -Wextra -pedantic -std=c99

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: all
	./$(TARGET)