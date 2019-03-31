CC = g++
CFLAGS = -std=c++11
OBJECTS = main.o Core.o Process.o Thread.o

Scheduler.out: $(OBJECTS)
	$(CC) $(OBJECTS) -o Scheduler.out

main.o: main.cpp libs/Core.h libs/Process.h libs/Thread.h
	$(CC) -c main.cpp $(CFLAGS)

Core.o: libs/Core.cpp libs/Core.h libs/Process.h libs/Thread.h
	$(CC) -c libs/Core.cpp $(CFLAGS)

Process.o: libs/Process.cpp libs/Core.h libs/Process.h libs/Thread.h
	$(CC) -c libs/Process.cpp $(CFLAGS)

Thread.o: libs/Thread.cpp libs/Core.h libs/Process.h libs/Thread.h
	$(CC) -c libs/Thread.cpp $(CFLAGS)

clean:
	-rm *.o *~ core paper
