#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct _NodeD {
	ElementType data;
	struct _NodeD* PrevNode;
	struct _NodeD* NextNode;

}NodeD;

typedef NodeD* pNodeD;

//DLL_Create
pNodeD DLL_Create(ElementType NewData) {
	pNodeD NewNode = (pNodeD)malloc(sizeof(NodeD));
	
	if (NewNode == NULL) {
		printf("메모리 할당 에러\n");
		exit(1);
	}

	NewNode->data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

//DLL_AppendNode
void DLL_AppendNode(pNodeD Head, pNodeD Tail, pNodeD NewNode) {
	NewNode->PrevNode = Tail->PrevNode;
	NewNode->NextNode = Tail;

	Tail->PrevNode->NextNode = NewNode;
	Tail->PrevNode = NewNode;
}

//DLL_InsertAfter
void DLL_InsertAfter(pNodeD Current, pNodeD NewNode) {
	if (Current == NULL || NewNode == NULL) {
		return;
	}
	NewNode->PrevNode = Current;
	NewNode->NextNode = Current->NextNode;
	
	if (Current->NextNode != NULL) {
		Current->NextNode->PrevNode = NewNode;
	}
	Current->NextNode = NewNode;
}

//DLL_Search
pNodeD DLL_Search(pNodeD Head, pNodeD Tail, ElementType TargetData){
	pNodeD Current = Head->NextNode;

	while (Current != Tail) {
		if (Current->data == TargetData) {
			return Current;
		}
		Current = Current->NextNode;
	}

	return NULL;
}

//DLL_Remove
void DLL_Remove(pNodeD Remove) {
	if (Remove == NULL || Remove->PrevNode == NULL || Remove->NextNode == NULL) {
		return;
	}

	Remove->PrevNode->NextNode = Remove->NextNode;
	Remove->NextNode->PrevNode = Remove->PrevNode;
	free(Remove);
}

//DLL_PrintList
void DLL_PrintList(pNodeD Head, pNodeD Tail) {
	pNodeD CurrentNode = Head->NextNode;
	while (CurrentNode != Tail) {
		printf("%d ", CurrentNode->data);
		CurrentNode = CurrentNode->NextNode;
	}
	printf("\n");

}


//DLL_Destroy
void DLL_Destroy(pNodeD Head, pNodeD Tail) {
	pNodeD CurrentNode = Head->NextNode;
	pNodeD tmp;
	while (CurrentNode != Tail) {
		tmp = CurrentNode;
		CurrentNode = CurrentNode->NextNode;
		free(tmp);
	}
}

int main() {
	// Head와 Tail 더미 노드를 생성하고 서로 연결
	pNodeD Head = DLL_CreateNode(0); // 더미 Head
	pNodeD Tail = DLL_CreateNode(0); // 더미 Tail

	Head->NextNode = Tail;
	Tail->PrevNode = Head;

	printf("초기 리스트 (비어있음):\n");
	DLL_PrintList(Head, Tail); // 출력: (아무것도 없음)

	// 1. 노드 추가 (맨 뒤에 Append)
	printf("노드 추가 (Append):\n");
	DLL_AppendNode(Head, Tail, DLL_CreateNode(10));
	DLL_AppendNode(Head, Tail, DLL_CreateNode(20));
	DLL_AppendNode(Head, Tail, DLL_CreateNode(30));
	DLL_PrintList(Head, Tail); // 출력: 10 20 30

	// 2. 노드 삽입 (특정 노드 뒤에 Insert After)
	printf("노드 삽입 (Insert After 20):\n");
	pNodeD SearchNode = DLL_SearchNode(Head, Tail, 20);
	if (SearchNode != NULL) {
		DLL_InsertAfter(SearchNode, DLL_CreateNode(25));
	}
	DLL_PrintList(Head, Tail); // 출력: 10 20 25 30

	// 3. 노드 검색
	printf("노드 검색 (Search 25):\n");
	SearchNode = DLL_SearchNode(Head, Tail, 25);
	if (SearchNode != NULL) {
		printf("데이터 25를 가진 노드를 찾았습니다: %d\n", SearchNode->Data);
	}
	else {
		printf("데이터 25를 가진 노드를 찾을 수 없습니다.\n");
	}

	// 4. 노드 삭제
	printf("노드 삭제 (Remove 25):\n");
	SearchNode = DLL_SearchNode(Head, Tail, 25);
	if (SearchNode != NULL) {
		DLL_RemoveNode(SearchNode);
	}
	DLL_PrintList(Head, Tail); // 출력: 10 20 30

	printf("노드 삭제 (Remove 10):\n");
	SearchNode = DLL_SearchNode(Head, Tail, 10);
	if (SearchNode != NULL) {
		DLL_RemoveNode(SearchNode);
	}
	DLL_PrintList(Head, Tail); // 출력: 20 30

	// 5. 리스트 메모리 해제
	printf("리스트 메모리 해제:\n");
	DLL_DestroyList(Head, Tail);
	// Head와 Tail 포인터는 더 이상 유효하지 않으므로 NULL로 설정하거나 함수 종료 후 사라집니다.

	return 0;
}