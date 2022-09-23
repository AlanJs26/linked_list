
CC = g++

FLAGS = -pedantic -Wall -O2

CPP = $(wildcard *.cpp algorithms/*.cpp)

all: run

run: main.exe
	main.exe

main.exe: ${CPP}
	@echo "Compiling all .cpp files"
	$(CC) ${CPP} ${FLAGS} -o main.exe

clean:
	@echo "Cleaning up..."
	rm *.exe *.o algorithms/*.exe algorithms/*.o