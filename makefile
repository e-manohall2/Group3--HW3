CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

OBJECTS = main.o address.o credit_card.o person.o store.o product.o transaction.o
DEPS = $(OBJECTS:.o=.d)

all: a.out

a.out: $(OBJECTS)
	$(CXX) $(OBJECTS) -o a.out

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJECTS) $(DEPS) a.out

.PHONY: all clean
