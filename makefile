.PHONY: all clean

all: a b

a: a.cpp
	clang++ -std=c++17 -DNDEBUG -O2 -Wall -o a a.cpp

b: b.cpp
	clang++ -std=c++17 -DNDEBUG -O2 -Wall -o b b.cpp

clean:
	rm -f a b
