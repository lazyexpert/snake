# Compiler
CC=g++

# Destination file
TARGET=build/snake

# Compilation flags
CFLAGS=-o

# Flags for SFML
LFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

# Source files
SOURCE=src/impl/*.cpp src/main.cpp src/Application.cpp src/Utils.cpp

# Header files
HEADERS=src/headers/*.hpp

# Combine
all: 
	$(CC) $(SOURCE) $(HEADERS) $(CFLAGS) $(TARGET) $(LFLAGS)