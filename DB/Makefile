t: Node.o BPTree.o main.o
	g++ -o t Node.o BPTree.o main.o

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

BPTree.o: BPTree.cpp BPTree.h
	g++ -c BPTree.cpp

main.o: main.cpp Node.h BPTree.h
	g++ -c main.cpp

clean:
	rm t Node.o BPTree.o main.o