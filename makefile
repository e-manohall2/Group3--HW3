CC=g++
V =-std=c++11

all:  main.o
	$(CC) $(V) main.o -o a.out 
main.o: address.o credit_card.o person.o store.o product.o transaction.o
	$(CC) -c $(V) main.cpp

address.o: address.cpp
	$(CC) $(V) address.cpp -c

credit_card.o: credit_card.cpp
	$(CC) $(V) credit_card.cpp -c
product.o: product.cpp
	$(CC) $(V) product.cpp -c

person.o: person.cpp address.o
	$(CC) $(V) person.cpp -c

transaction.o: transaction.cpp person.o
	$(CC) $(V) transaction.cpp -c
store.o: store.cpp product.o transaction.o person.o
	$(CC) $(V) store.cpp -c
clean: 
	rm -f *.o 
