CC = g++
CFLAGS = -c -Wall -Wextra


TARGET = game_library


all: $(TARGET)


$(TARGET): main.o library.o
	$(CC) -g -Wextra -Wall -o $(TARGET) main.o library.o


library.o: library.cpp library.h game.h
	$(CC) $(CFLAGS) library.cpp


main.o: main.cpp library.h game.h
	$(CC) $(CFLAGS) main.cpp


clean:
	$(RM) $(TARGET) *.o *~
