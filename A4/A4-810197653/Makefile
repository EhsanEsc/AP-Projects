CC = g++ -std=c++11

all: Scheduler.out

Scheduler.out: main.o Core.o Process.o Thread.o
	${CC} main.o Core.o Process.o Thread.o -o Scheduler.out

main.o: main.cpp Core.cpp Core.h Process.cpp Process.h Thread.cpp Thread.h
	${CC} -c main.cpp

Core.o: Core.cpp Core.h Process.cpp Process.h Thread.cpp Thread.h
	${CC} -c Core.cpp

Process.o: Process.cpp Process.h Thread.cpp Thread.h
	${CC} -c Process.cpp

Thread.o: Process.cpp Process.h Thread.cpp Thread.h
	${CC} -c Thread.cpp

.PHONY: clean
clean:
	rm *.o
	rm Scheduler.out
