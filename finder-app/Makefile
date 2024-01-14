CC = gcc
CROSS_COMPILE ?=

SRC = writer.c
OBJ = $(SRC:.c=.o)
EXE = writer

# Default target
all: $(EXE)

$(EXE): $(OBJ)
	$(CROSS_COMPILE)$(CC) -o $@ $^

%.o: %.c
	$(CROSS_COMPILE)$(CC) -c -o $@ $<

# Clean target
clean:
	rm -f $(EXE) $(OBJ)

.PHONY: all clean

