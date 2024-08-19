
TARGET = bin/sistema_pedidos


CC = gcc


CFLAGS = -Wall -Wextra -std=c11 -Iinclude


SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin


SRCS = $(wildcard $(SRCDIR)/*.c)


OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))


all: $(TARGET)


$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)


$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJDIR) $(BINDIR)


run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run