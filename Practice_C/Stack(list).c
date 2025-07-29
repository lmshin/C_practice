#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct _Node {
	ElementType data;
	struct _Node* next;
}Node;
typedef Node* pNode;

typedef struct _Stack {
	pNode Top;
	int Count;
}Stack;

typedef Stack* pStack;

pStack CreateStack() {
	pStack newStack = (pStack)malloc(sizeof(Stack));
	if (newStack == NULL) {
		printf("할당실패");
		exit(1);
	}

	//pNode TopNode = (pNode)malloc(sizeof(Node)); 
	newStack->Top = NULL;
	newStack->Count = 1;

	return newStack;
}

void DeleteStack(pStack stack) {
	pNode Current = stack->Top;
	pNode tmp;
	while (Current->next != NULL) {
		tmp = Current;
		Current = Current->next;
		free(tmp);
	}
	free(stack);
}

//CreateNode
pNode CreateNode(ElementType NewData) {
	pNode NewNode = (pNode)malloc(sizeof(Node));
	if(NewNode == NULL){
		printf("Node 할당실패");
		exit(1);
	}

	NewNode->next = NULL;
	NewNode->data = NewData;

	return NewNode;
}

//push
void Push(pStack stack, pNode NewNode) {
	if (stack == NULL || NewNode == NULL)
		return;

	NewNode->next = stack->Top;
	stack->Top = NewNode;
	stack->Count++;
}

//pop
ElementType Pop(pStack stack) {
	if (stack->Count == 0) {
		printf("stack 이 비어있습니다.");
		return;
	}

	pNode poppedNode = stack->Top;
	stack->Top = stack->Top->next;
	ElementType result = poppedNode->data;
	free(poppedNode);
	stack->Count--;
	return result;
}

//top
ElementType top(pStack stack) {
	if (stack == NULL || stack->Top == NULL || isempty(stack)) {
		printf("stack 이 비어 있습니다.");
		exit(1);
	}
	return stack->Top->data;
}

//IsEmpty
int IsEmpty(pStack stack){
	return stack->Top == NULL;
}

//size
int GetSize(pStack stack) {
	return stack->Count;
}

int main() {
	pStack myStack = CreateStack(); // 스택 생성

	printf("스택 초기 상태: 비어있음? %s, 크기: %d\n", IsEmpty(myStack) ? "Yes" : "No", GetSize(myStack));

	// Push 연산
	printf("\n--- Push 연산 ---\n");
	Push(myStack, CreateNode(10));
	printf("Push 10. 스택 탑: %d, 크기: %d\n", Peek(myStack), GetSize(myStack));
	Push(myStack, CreateNode(20));
	printf("Push 20. 스택 탑: %d, 크기: %d\n", Peek(myStack), GetSize(myStack));
	Push(myStack, CreateNode(30));
	printf("Push 30. 스택 탑: %d, 크기: %d\n", Peek(myStack), GetSize(myStack));

	printf("\n현재 스택 상태: 비어있음? %s, 크기: %d\n", IsEmpty(myStack) ? "Yes" : "No", GetSize(myStack));

	// Peek 연산
	printf("\n--- Peek 연산 ---\n");
	printf("스택 탑 확인 (Peek): %d\n", Peek(myStack));

	// Pop 연산
	printf("\n--- Pop 연산 ---\n");
	printf("Pop: %d. 스택 탑: %d, 크기: %d\n", Pop(myStack), Peek(myStack), GetSize(myStack)); // 30 pop
	printf("Pop: %d. 스택 탑: %d, 크기: %d\n", Pop(myStack), Peek(myStack), GetSize(myStack)); // 20 pop
	printf("Pop: %d. 스택 탑: %d, 크기: %d\n", Pop(myStack), GetSize(myStack)); // 10 pop (여기서 Peek 하면 오류)

	printf("\n모든 요소 Pop 후 스택 상태: 비어있음? %s, 크기: %d\n", IsEmpty(myStack) ? "Yes" : "No", GetSize(myStack));

	// 비어있는 스택에서 Pop/Peek 시도 (오류 발생)
	// Pop(myStack); // 이 줄의 주석을 해제하면 에러 메시지 출력 후 프로그램 종료
	// Peek(myStack); // 이 줄의 주석을 해제하면 에러 메시지 출력 후 프로그램 종료

	// 스택 메모리 해제
	DestroyStack(myStack);
	printf("\n스택 메모리 해제 완료.\n");

	return 0;
}