CC = gcc
CFLAGS = -Wall
TARGET = m.exe

PREF_SRC = ./src/

SRC = $(wildcard $(PREF_SRC)*.c)
OBJ = $(patsubst $(PREF_SRC)%.c, %.o, $(SRC))

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: $(PREF_SRC)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q *.o