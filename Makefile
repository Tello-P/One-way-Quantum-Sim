CC = gcc
CFLAGS = -Wall -Wextra -Iincludes
LDFLAGS = -lm
SRC = src/quantum_state.c
OBJ = $(SRC:.c=.o)
TARGET = bin/quantum_engine

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRC)/*.o $(TARGET)
