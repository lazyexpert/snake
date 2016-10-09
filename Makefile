# Compiler
CC=g++

# Source files
SOURCES=src/main.cpp src/impl/Logger.cpp src/Application.cpp src/Utils.cpp src/impl/Controller.cpp src/headers/Model.hpp src/impl/Model.cpp src/headers/Logger.hpp src/headers/View.hpp src/impl/View.cpp src/headers/Controller.hpp

# Destination file
TARGET=build/snake

# Compilation flags
CFLAGS=-o

# Combine
all:
	$(CC) $(SOURCES) $(CFLAGS) $(TARGET)