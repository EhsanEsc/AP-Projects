CC = g++
CFLAGS = -std=c++11
FILE_SYSTEM_LIST = file_system.h Element.h Dir.h File.h Link.h Errors.h

2.out: main.o file_system_interface.o file_system.o dir.o link.o file.o element.o
	$(CC) $(CFLAGS) main.o file_system_interface.o file_system.o dir.o link.o file.o element.o -o 2.out
main.o: main.cpp file_system_interface.h $(FILE_SYSTEM_LIST)
	$(CC) $(CFLAGS) -c main.cpp -o main.o
file_system_interface.o: file_system_interface.cpp file_system_interface.h $(FILE_SYSTEM_LIST)
	$(CC) $(CFLAGS) -c file_system_interface.cpp -o file_system_interface.o
file_system.o: file_system.cpp $(FILE_SYSTEM_LIST)
	$(CC) $(CFLAGS) -c file_system.cpp -o file_system.o
dir.o: Dir.cpp Dir.h Element.h Errors.h
	$(CC) $(CFLAGS) -c Dir.cpp -o dir.o
file.o: File.cpp File.h Element.h Errors.h
	$(CC) $(CFLAGS) -c File.cpp -o file.o
link.o: Link.cpp Link.h Element.h Errors.h
	$(CC) $(CFLAGS) -c Link.cpp -o link.o
element.o: Element.cpp Element.h Errors.h
	$(CC) $(CFLAGS) -c Element.cpp -o element.o
clean:
	rm *.o *.out
