# wpisz 'make' aby skompilować cały program


CC = g++ -pthread -g -Wpedantic -Wall -std=c++17 

all: func.o main.o
	$(CC) func.o main.o -o generate
func.o: func.cpp person.hpp struct.hpp
	$(CC) func.cpp -c -o func.o
main.o: main.cpp person.hpp
	$(CC) main.cpp -c -o main.o
clean:
	rm -f *.o generate
