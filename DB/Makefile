t: Node.o BPTree.o Table.o Database.o main.o
	g++ -o t Node.o BPTree.o Table.o Database.o main.o

Node.o: Node.cpp Node.h List.h
	g++ -c Node.cpp

BPTree.o: BPTree.cpp BPTree.h Node.h List.h
	g++ -c BPTree.cpp

Table.o: Table.cpp Table.h BPTree.h Error.h Command.h
	g++ -c Table.cpp

Database.o: Database.cpp Database.h Table.h Error.h Command.h
	g++ -c Database.cpp

main.o: main.cpp Database.h Table.h BPTree.h Node.h List.h Error.h Command.h
	g++ -c main.cpp

clean:
	rm t Node.o BPTree.o Table.o Database.o main.o