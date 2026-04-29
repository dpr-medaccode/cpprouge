CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I./include
LDFLAGS = -lraylib

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/mapa.cpp $(SRC_DIR)/sala.cpp
OBJECTS = $(OBJ_DIR)/main.o $(OBJ_DIR)/mapa.o $(OBJ_DIR)/sala.o
EXECUTABLE = cpprouge.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

.PHONY: all clean