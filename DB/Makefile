t: Node.o BPTree.o main.o
	g++ -o t Node.o BPTree.o main.o

Node.o: Node.h
	g++ -c Node.o Node.c

BPTree.o: BPTree.h
	g++ -c BPTree.o BPTree.c

main.o: Node.h BPTree.h
	g++ -c main.o main.c

clean:
	rm BPTree.o main.o Node.o t