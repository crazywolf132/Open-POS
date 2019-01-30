CC=g++
CFLAGS=-I.

all: pos.o orders.o stock.o
	$(CC) -o pos pos.o orders.o stock.o

clean:
	rm -rf ./*.o
	rm -rf ./pos