CC = g++
CFLAGS = -g -Wall

MainBT: MainBT.o BSTree.o BinaryTree.o Heap.o

MainH: MainH.o Heap.o Heap.o BinaryTree.o BSTree.o

MainH.o: Main.cpp
	$(CC) -c -DH $(CFLAGS) -o MainH.o Main.cpp

MainBT.o: Main.cpp
	$(CC) -c -DBT $(CFLAGS) -o MainBT.o Main.cpp

BSTree: BSTree.o BinaryTree.o 

BSTree.o: BSTree.cpp BinaryTree.h

BinaryTree: BinaryTree.o 

BinaryTree.o: BinaryTree.cpp BinaryTree.h

Heap.o: Heap.cpp Heap.h

.PHONY: clean
clean:
	rm -f *.o a.out Main MainH MainBT
