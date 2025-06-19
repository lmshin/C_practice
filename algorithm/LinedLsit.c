#if 01

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

void insert_front(Node** head, int data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = *head;
	*head = new_node;
}

void insert_back(Node** head, int data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	if (*head == NULL) {
		*head = new_node;
		return;
	}

	Node* curr = *head;
	while (curr->next != NULL) {
		curr = curr->next;
	}

	curr->next = new_node;
}

void delete_value(Node** head, int value) {
	Node* curr = *head;
	Node* prev = NULL;

	while (curr != NULL && curr->next->data != value) {
		prev = curr;
		curr = curr->next;
	}

	if (curr == NULL) {
		printf("값 %d 를 찾을 수 없습니다.\n", value);
		return;
	}

	if (prev == NULL) {
		*head = curr->next;
	}
	else {
		prev->next = curr->next;
	}
	
	free(curr);
}

void print_list(Node* head) {
	if (head == NULL) {
		printf("비어있음!");
	}
	Node* curr = head;
	while (curr != NULL) {
		printf("%2d", curr->data);
		curr = curr->next;
	}
}

void free_list(Node* head) {
	Node* temp;
	Node* curr = head;

	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

#endif

#if 02
typedef int ElementType;
typedef struct _NodeD {
	ElementType Data;
	struct _NodeD* prev;
	struct _NodeD* next;
}NodeD;
typedef NodeD* pNodeD;

typedef struct _NodeT {
	ElementType Data;
	struct _NodeT* left;
	struct _NodeT* right;
}NodeT;
typedef NodeT* pNodeT;

NodeD* DLL_CreateNode(ElementType value) {
	NodeD* new_node = (NodeD*)malloc(sizeof(NodeD));
	
	if (new_node == NULL) {
		exit(1);
	}

	new_node->Data = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	
	return new_node;
}

NodeT* Tree_CreateNode(ElementType value) {
	NodeT* new_node = (NodeT*)malloc(sizeof(NodeT));

	if (new_node == NULL) {
		exit(1);
	}

	new_node->Data = value;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

int main(void) {
	pNodeD Head = DLL_CreateNode(0);
	pNodeD Tail = DLL_CreateNode(0);
	Head->next = Tail;
	Tail->prev = Head;

	NodeD A, B, C;
	
	A = (NodeD){ 10,NULL,&B };
	B = (NodeD){ 20,&A,&C };
	C = (NodeD){ 30,&B,NULL };

	Head->next = &A;
	A.prev = NULL;
	A.Data = 10;
	A.next = &B;
	B.prev = &A;
	B.next = &C;
	C.prev = &B;
	C.next = NULL;
	Tail->prev = &C;
	
	pNodeD tmp = &A;
	while (tmp != NULL) {
		printf("%d ", tmp->Data);
		tmp = tmp->next;
	}
	printf("\n");

	pNodeT A2, B2, C2, D2, E2;
	A2 = Tree_CreateNode(1);
	B2 = Tree_CreateNode(2);
	C2 = Tree_CreateNode(3);
	D2 = Tree_CreateNode(4);
	E2 = Tree_CreateNode(5);
	A2->left = B2;
	A2->right = C2;
	B2->left = D2;
	B2->right = E2;

	//A2 = (NodeT){ 10,&B2,&C2 };
	//B2 = (NodeT){ 20, &D2,&E2 };
	//C2 = (NodeT){ 30,NULL,NULL };
	//D2 = (NodeT){ 40,NULL,NULL };
	//E2 = (NodeT){ 50,NULL,NULL };

	printf("A %d %d %d\n", A2->Data, A2->left->Data, A2->left->left->Data);
	printf("A %d %d %d\n", A2->Data, A2->left->Data, A2->left->right->Data);
}

#endif // 02