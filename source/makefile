.PHONY: all test mainfiles clean

all: mainfiles

mainfiles:
	g++ main.cpp character.cpp equipment.cpp map.cpp -lncurses

test: 
	g++ test.cpp character.cpp equipment.cpp -o test

clean: 
	rm -f a.out test
