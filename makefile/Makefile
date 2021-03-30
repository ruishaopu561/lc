a: main.o trie.o node.o
	g++ -o main.o trie.o node.o

main.o: main.cpp trie.h node.h
	g++ -c main.cpp

trie.o: trie.cpp trie.h node.h
	g++ -c trie.cpp

node.o: node.cpp node.h
	g++ -c node.cpp

clean:
	rm a trie.o node.o