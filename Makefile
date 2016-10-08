CC=g++
SOURCES=src/main.cpp src/Application.cpp
TARGET=build/snake

all:
	$(CC) $(SOURCES) -o $(TARGET)