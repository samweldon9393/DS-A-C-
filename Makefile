CC = g++

Main: Main.o BSTree.o BinaryTree.o

Main.o: Main.cpp

BSTree: BSTree.o BinaryTree.o BinaryTree.h

BSTree.o: BSTree.cpp BinaryTree.h

BinaryTree: BinaryTree.o BinaryTree.h

BinaryTree.o: BinaryTree.cpp BinaryTree.h

.PHONY: clean
clean:
	rm -f *.o BinaryTree
