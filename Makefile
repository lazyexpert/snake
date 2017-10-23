# Compiler
CC=g++

# Destination file
TARGET=build/snake

# Compilation flags
CFLAGS= -std=c++11

# Flags for SFML
LFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

# Source files
SOURCE=src/impl/*.cpp src/main.cpp

# Header files
HEADERS=src/headers/*.hpp

# Combine
all: 
	$(CC) $(SOURCE) $(HEADERS) $(CFLAGS) -o $(TARGET) $(LFLAGS)

compile:
	$(CC) *.o $(CFLAGS) -o $(TARGET) $(LFLAGS)

model:
	$(CC) src/impl/Model.cpp $(HEADERS) $(CFLAGS) -c

clean:
	rm build/*.o