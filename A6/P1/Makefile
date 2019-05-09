
CC = g++
CFLAGS = -std=c++11

1.out: main.o shape.o sphere.o cuboid.o cone.o
	$(CC) $(CFLAGS) main.o shape.o sphere.o cuboid.o cone.o -o 1.out

main.o: main.cpp shape.h sphere.h cuboid.h cone.h
	$(CC) $(CFLAGS) -c main.cpp -o main.o
shape.o: shape.cpp shape.h
	$(CC) $(CFLAGS) -c shape.cpp -o shape.o
sphere.o: sphere.cpp shape.h sphere.h
	$(CC) $(CFLAGS) -c sphere.cpp -o sphere.o
cuboid.o: cuboid.cpp cuboid.h shape.h
	$(CC) $(CFLAGS) -c cuboid.cpp -o cuboid.o
cone.o: cone.cpp cone.h shape.h
	$(CC) $(CFLAGS) -c cone.cpp -o cone.o

clean:
	rm *.o *.out
