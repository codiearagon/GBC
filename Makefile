SOURCES = main.cpp

all:
	g++ -I src/include -I src/chip8 -L src/lib -o main $(SOURCES) -lmingw32 -lSDL2main -lSDL2