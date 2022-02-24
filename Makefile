main.exe: main.o
	g++ main.o -o main.exe

main.o: main.cpp set.h
	g++ -c -std=c++11 main.cpp -o main.o
