# Compiler
CC=g++

# Destination file
TARGET=build/snake

# Compilation flags
CFLAGS= -std=c++11 -o

# Flags for SFML
LFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

# Source files
SOURCE=src/impl/*.cpp src/main.cpp

# Header files
HEADERS=src/headers/*.hpp

# Combine
all: 
	$(CC) $(SOURCE) $(HEADERS) $(CFLAGS) $(TARGET) $(LFLAGS)