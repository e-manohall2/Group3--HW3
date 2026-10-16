CC=g++
V =-std=c++11

all:  main.o
	$(CC) $(V) main.o -o a.out 
main: address.o credit_card.o person.o store.o product.o transaction.o
	$(CC) -c $(V) main.cpp

address: address.cpp
	$(CC) $(V) address.cpp -c

credit_card: credit_card.cpp
	$(CC) $(V) credit_card.cpp -c
product: product.cpp
	$(CC) $(V) product.cpp -c

person: person.cpp address.out
	$(CC) $(V) person.cpp -c

transaction: transaction.cpp person.o
	$(CC) $(V) transaction.cpp -clean
store: store.cpp product.o transaction.o person.o
	$(CC) $(V) store.cpp -c
clean: 
	rm -f *.o 
