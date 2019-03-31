CC = g++
CFLAGS = -std=c++11
OBJECTS = main.o libs/Core.o libs/Process.o libs/Thread.o
DEP = libs/Core.h libs/Process.h libs/Thread.h

Scheduler.out: $(OBJECTS)
	$(CC) $(OBJECTS) -o Scheduler.out

libs/%.o : libs/%.cpp $(DEP)
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.cpp $(DEP)
	$(CC) $(CFLAGS) -c $<

clean:
	-rm *.o *~ core paper
	-rm libs/*.o libs/*~ core paper
