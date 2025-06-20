#include<stdio.h>

typedef int ElementType;
typedef struct _HeapNode {
	ElementType data;
}HeapNode;

typedef struct _Heap {
	HeapNode* Heap;
	int used_size;
	int capacity;
} Heap;

Heap* createHeap(int capacity) {

}