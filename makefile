CC = gcc
CFLAGS = -g -Wall -std=c11 -Iinclude
LIBS =
TARGET = run

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
_DEPS = main.h parser.h checker.h
_OBJS = main.o parser.o checker.o

DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET)
