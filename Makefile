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

model.o:
	$(CC) src/impl/Model.cpp $(CFLAGS) -c

view.o:
	$(CC) src/impl/View.cpp $(CFLAGS) -c

controller.o:
	$(CC) src/impl/Controller.cpp $(CFLAGS) -c

application.o:
	$(CC) src/impl/Application.cpp $(CFLAGS) -c

main.o:
	$(CC) src/main.cpp $(CFLAGS) -c

clean:
	rm *.o

compile: model.o view.o controller.o application.o main.o

# Combine
all:
	$(CC) *.o -o $(TARGET) $(LFLAGS) && make clean
