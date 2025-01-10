CC = g++

BinaryTree: BinaryTree.cpp BinaryTree.h

.PHONY: clean
clean:
	rm -f *.o BinaryTree
