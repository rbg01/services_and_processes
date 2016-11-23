CC=g++

ejecutable: main.o terminal.o vectores.o
	$(CC) main.o terminal.o vectores.o  -o ejecutable 

main.o: main.cpp terminal.h general.h
	$(CC) -I ../include -c main.cpp

terminal.o: terminal.cpp terminal.h
	$(CC) -I ../include -c terminal.cpp

vectores.o: vectores.cpp vectores.h
	$(CC) -I ../include -c vectores.cpp




.PHONY: clean

clean:
	rm *.o ejecutable

