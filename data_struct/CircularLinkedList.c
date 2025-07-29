#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct _NodeC {
	ElementType data;
	struct _NodeC* next;
} NodeC;

typedef NodeC* pNodeC;
//CLL_CreateNode
pNodeC CLL_CreateNode(ElementType NewData) {
	pNodeC NewNode = (pNodeC)malloc(sizeof(NodeC));

	if (NewNode == NULL) {
		printf("메모리 할당 실패");
		exit(1);
	}

	NewNode->data = NewData;
	NewNode->next = NULL;

	return NewNode;
}

//CLL_AppendNode
void CLL_AppendNode(pNodeC* Head, pNodeC NewNode) {
	if (*Head == NULL) {
		*Head = NewNode;
		NewNode->next = NewNode;
	}
	else {
		pNodeC Tail = *Head;
		while (Tail->next != *Head) {
			Tail = Tail->next;
		}

		Tail->next = NewNode;
		NewNode->next = *Head;
	}
}

//CLL_InsertAfter
void CLL_InsertAfter(pNodeC Current, pNodeC NewNode) {
	if (Current == NULL || NewNode == NULL) {
		return;
	}
	NewNode->next = Current->next;
	Current->next = NewNode;
}
//CLL_SearchNode
pNodeC CLL_SearchNode(pNodeC Head, ElementType TargetData) {
	pNodeC Current = Head;
	do {
		if (Current->data == TargetData) {
			return Current;
		}

		Current = Current->next;
	} while (Current != Head);

	return NULL;
}

//CLL_RemoveNode
void CLL_RemoveNode(pNodeC* Head, pNodeC Remove) {
	if (*Head == NULL || Remove == NULL) {
		return;
	}

	if (*Head == Remove && (*Head)->next == *Head) {
		free(Remove);
		*Head = NULL;
		return;
	}


	if (*Head == Remove) {

		pNodeC Tail = *Head;
		while (Tail->next != *Head) {
			Tail = Tail->next;
		}
		*Head = Remove->next;
		Tail->next = *Head;
	}
	else {

		pNodeC Current = *Head;
		while (Current != NULL && Current->next != Remove) {
			Current = Current->next;
			if (Current == *Head) {
				return;
			}
		}

		if (Current != NULL && Current->next == Remove) { // Current가 Remove의 이전 노드일 경우
			Current->next = Remove->next;
		}
	}
	free(Remove);
}

//CLL_PrintList
void CLL_PrintList(pNodeC Head) {
	if (Head == NULL) {
		printf("리스트가 비어있습니다.\n");
		return;
	}

	pNodeC Current = Head;
	do {
		printf("%d ", Current->data);
		Current = Current->next;
	} while (Current != Head);
	printf("\n");
}

//CLL_DestroyList
void CLL_DestroyList(pNodeC* Head) {
	if (*Head == NULL) {
		return;
	}

	pNodeC Current = *Head;
	pNodeC NextNode = NULL;

	do {
		NextNode = Current->next;
		free(Current);
		Current = NextNode;
	} while (Current != *Head);

	*Head = NULL;
}

int main() {
	pNodeC Head = NULL; // 리스트의 시작(Head)은 처음에는 NULL입니다.

	// 1. 노드 추가 (맨 뒤에 Append)
	printf("노드 추가 (Append):\n");
	CLL_AppendNode(&Head, CLL_CreateNode(10));
	CLL_AppendNode(&Head, CLL_CreateNode(20));
	CLL_AppendNode(&Head, CLL_CreateNode(30));
	CLL_PrintList(Head); // 출력: 10 20 30

	// 2. 노드 삽입 (특정 노드 뒤에 Insert After)
	printf("노드 삽입 (Insert After 20):\n");
	pNodeC SearchNode = CLL_SearchNode(Head, 20);
	if (SearchNode != NULL) {
		CLL_InsertAfter(SearchNode, CLL_CreateNode(25));
	}
	CLL_PrintList(Head); // 출력: 10 20 25 30

	// 3. 노드 검색
	printf("노드 검색 (Search 25):\n");
	SearchNode = CLL_SearchNode(Head, 25);
	if (SearchNode != NULL) {
		printf("데이터 25를 가진 노드를 찾았습니다: %d\n", SearchNode->Data);
	}
	else {
		printf("데이터 25를 가진 노드를 찾을 수 없습니다.\n");
	}

	// 4. 노드 삭제
	printf("노드 삭제 (Remove 25):\n");
	SearchNode = CLL_SearchNode(Head, 25);
	if (SearchNode != NULL) {
		CLL_RemoveNode(&Head, SearchNode);
	}
	CLL_PrintList(Head); // 출력: 10 20 30

	printf("Head 노드 삭제 (Remove 10):\n");
	SearchNode = CLL_SearchNode(Head, 10);
	if (SearchNode != NULL) {
		CLL_RemoveNode(&Head, SearchNode);
	}
	CLL_PrintList(Head); // 출력: 20 30

	printf("마지막 남은 노드 삭제 (Remove 20):\n");
	SearchNode = CLL_SearchNode(Head, 20);
	if (SearchNode != NULL) {
		CLL_RemoveNode(&Head, SearchNode);
	}
	CLL_PrintList(Head); // 출력: 리스트가 비어있습니다.

	// 5. 리스트 메모리 해제 (위에서 이미 노드를 다 삭제했으므로 Head는 NULL)
	printf("리스트 메모리 해제:\n");
	CLL_DestroyList(&Head);
	CLL_PrintList(Head); // 출력: 리스트가 비어있습니다.

	return 0;
}