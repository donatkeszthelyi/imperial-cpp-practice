main : main.o braille.o
	g++ -g -Wall main.o braille.o -o main

main.o : main.cpp braille.h
	g++ -g -Wall -c main.cpp

braille.o : braille.cpp braille.h
	g++ -g -Wall -c braille.cpp

clean:
	rm *.o main
