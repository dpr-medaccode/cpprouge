CC = g++
CFLAGS  = -Wall -Wextra -std=c11
LIBS = -lraylib -lm

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.cpp)          
OBJS  = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) 
TARGET = cpprouge

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

re: clean all

.PHONY: all clean re

run: $(TARGET)
	./$(TARGET)