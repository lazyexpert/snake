# Compiler
CC=g++

# Source files
SOURCES=src/main.cpp src/Application.cpp src/Utils.cpp

# Destination file
TARGET=build/snake

# Compilation flags
CFLAGS=-o

# Combine
all:
	$(CC) $(SOURCES) $(CFLAGS) $(TARGET)