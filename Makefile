CC=g++
SOURCES=src/Logger.cpp src/main.cpp src/Application.cpp src/Utils.cpp
TARGET=build/snake

all:
	$(CC) $(SOURCES) -o $(TARGET)