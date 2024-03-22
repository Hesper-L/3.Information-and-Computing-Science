#pragma once

#define MAX_TREE_SIZE 100

typedef char ElemType;
typedef struct PTNode {
	ElemType data;
	int parent;          
} PTNode;

typedef struct {
	PTNode nodes[MAX_TREE_SIZE];
	int root, n;      
}PTree;

bool createPTree(PTree& T);
void visitPT(PTree& T);