SOURCES = main.cpp src/gbc/gbc.cpp src/gbc/cpu.cpp src/gbc/bus.cpp src/gbc/wram.cpp

all:
	g++ -I src/include -I src/gbc -L src/lib -o main $(SOURCES) -lmingw32 -lSDL2main -lSDL2