#if 01

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int ElementType;
typedef struct _HeapNode {
	ElementType data;
}HeapNode;

typedef struct _Heap {
	HeapNode* nodes;
	int capacity;
	int used_size;
}Heap;

Heap* HEAP_Create(int capacity) { //왜 Heap*를 반환하지??
	Heap* new_heap = NULL;
	new_heap = (Heap*)calloc(1, sizeof(Heap));

	if (new_heap == NULL) {
		printf("heap 생성 불가\n");
		exit(1);
	}

	new_heap->capacity = capacity;
	new_heap->nodes = (HeapNode*)calloc(capacity + 1, sizeof(HeapNode));
	if (new_heap->nodes == NULL) {
		free(new_heap);
		exit(1);
	}
	new_heap->used_size = 0;

	return new_heap;
}

void destroy_Heap(Heap* h) {
	free(h->nodes);
	free(h);
}

void swap(HeapNode* a, HeapNode* b) {
	ElementType tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

//노드 삽입 insert?
void Heap_Insert(Heap * minHeap, ElementType newData) {
	
	if (minHeap->used_size >= minHeap->capacity) {
		printf("full!");
		return;
	}

	int current_Idx = minHeap->used_size + 1; //index가 1부터 시작하므로
	int parents_idx = current_Idx / 2;

	//먼저 제일 우측에 새 노드를 추가,
	minHeap->nodes[current_Idx].data = newData;

	//부모 노드와 비교해서 작으면 위치를 바꿈
	while (current_Idx != 1 && minHeap->nodes[parents_idx].data > minHeap->nodes[current_Idx].data) {

		swap(minHeap->nodes + current_Idx, minHeap->nodes + parents_idx);
		/*ElementType tmp = minHeap->nodes[parents_idx].data;
		minHeap->nodes[parents_idx].data = minHeap->nodes[current_Idx].data;
		minHeap->nodes[current_Idx].data = tmp;*/
		
		//다음 비교를 위해 인덱스를 변경해 준다.
		current_Idx = parents_idx;
		parents_idx = current_Idx / 2;;

	}

	minHeap->used_size++;
	return;
}

//노드 삭제 delete
ElementType Heap_Delete(Heap* minHeap) {
	
	if (minHeap->used_size == 0) return -1; 

	int current_Idx = 1;
	int left = current_Idx * 2;
	int right = current_Idx * 2 + 1;

	ElementType return_value = minHeap->nodes[1].data;

	//맨처음 node에 마지막 노드를 넣는다
	minHeap->nodes[1].data = minHeap->nodes[minHeap->used_size].data;
	minHeap->used_size--; //전체 사이즈 줄이기

	int smallest = current_Idx;
	//부모노드가 자식보다 클 경우 교체
	
	
	while (left <= minHeap->used_size) {//자식 노드가 최대 사이즈보다 커지면 안됨


		if (minHeap->nodes[current_Idx].data < minHeap->nodes[left].data) {//현재값이 왼쪽 자식 보다 작으면  idx 에 담아둔다.
			smallest = left;
		}
		
		if (right <= minHeap->used_size && minHeap->nodes[right].data < minHeap->nodes[smallest].data) {
			smallest = right;
		}
		
		if(smallest == current_Idx) break;//잘 들어간 거니까 break;

		swap(minHeap->nodes + current_Idx, minHeap->nodes + smallest);
		current_Idx = smallest;
		left = current_Idx * 2;
		right = current_Idx * 2 + 1;

	}

	return return_value;
}

void Heap_printf(Heap* minHeap) {
	for (int i = 1; i <= minHeap->used_size; i++) {
		printf("%d ", minHeap->nodes[i].data);
	}
	printf("\n");
}

int main() {
	int N;
	Heap* minHeap;
	(void)freopen("pq_data.txt","rt",stdin);
	(void)scanf("%d", &N);
	minHeap = HEAP_Create(N + 1);
	//printf("%d %p\n", minHeap->capacity, minHeap->nodes);

	minHeap->nodes[0].data = 0;
	Heap_Insert(minHeap, 10);
	Heap_Insert(minHeap, 20);
	Heap_Insert(minHeap, 30);
	Heap_Insert(minHeap, 40);

	//printf("%d\n", minHeap->nodes[0].data);
	Heap_printf(minHeap);
}

#endif