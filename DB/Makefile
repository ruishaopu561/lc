t: Node.o BPTree.o Parser.o Commander.o main.o
	g++ -o t Node.o BPTree.o Parser.o Commander.o main.o

Node.o: Node.cpp Node.h List.h
	g++ -c Node.cpp

BPTree.o: BPTree.cpp BPTree.h Node.h List.h
	g++ -c BPTree.cpp

Parser.o: Parser.cpp Parser.h BPTree.h
	g++ -c Parser.cpp

Commander.o: Commander.cpp Commander.h Parser.h
	g++ -c Commander.cpp

main.o: main.cpp Commander.h Parser.h BPTree.h Node.h List.h
	g++ -c main.cpp

clean:
	rm t Node.o BPTree.o Parser.o Commander.o main.o