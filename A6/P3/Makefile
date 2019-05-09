
CC = g++
CFLAGS = -std=c++11
DEP = player.h striker.h goalkeeper.h defender.h
OBJ = main.o game_manager.o manager.o player.o defender.o striker.o goalkeeper.o

3.out: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o 3.out
main.o: main.cpp game_manager.h manager.h $(DEP)
	$(CC) $(CFLAGS) -c main.cpp -o main.o
game_manager.o: game_manager.cpp game_manager.h manager.h $(DEP)
	$(CC) $(CFLAGS) -c game_manager.cpp -o game_manager.o
manager.o: manager.cpp manager.h $(DEP)
	$(CC) $(CFLAGS) -c manager.cpp -o manager.o
player.o: player.cpp $(DEP)
	$(CC) $(CFLAGS) -c player.cpp -o player.o
defender.o: defender.cpp $(DEP)
	$(CC) $(CFLAGS) -c defender.cpp -o defender.o
striker.o: striker.cpp $(DEP)
	$(CC) $(CFLAGS) -c striker.cpp -o striker.o
goalkeeper.o: goalkeeper.cpp $(DEP)
	$(CC) $(CFLAGS) -c goalkeeper.cpp -o goalkeeper.o

clean:
	rm *.o *.out
