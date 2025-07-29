#include "day04.h"

//배열을 넘겨주는 대신 파라미터로 int * p 대신 int p[] 이렇게 쓴다. 이렇게 써도 똑같이 동작한다, 대괄호 내부에 숫자를 써도 아무런 의미가 없다.
void my_gets(char str[], int size) {
	char ch;
	int i = 0;
	while (i < size - 1) {
		ch = getchar();
		
		if (ch == '\n') {
			str[i] = ch;
			break;
		}
		str[i++] = ch;
	}

	str[i] = '\0';
	printf("%s", str);

	return;
}

void f08_2(void) {
	int ary[3][2];
	for (int i = 0; i < 3; i++) {
		//scanf("%d %d", &ary[i][0], &ary[i][1]);
		scanf("%d %d", ary[i], ary[i]+1);
	}

	for (int i = 0; i < 3; i++) {
		printf("%d %d\n", ary[i][0], ary[i][1]);
	}
}

void f08_2_extra(void) {
	char ary[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		(void)scanf("%c", ary + i);
	}

	for (int i = 0; i < 3; i++) {
		printf("%d", *(ary + i));
	}
}

void my_func1(int* p) {
	printf("int * : %d\n", sizeof(p));
}

void my_func2(int p[100]) {
	printf("int p[] : %d\n", sizeof(p));
}

void f07_3(void) {
	int ary[3] = { 10, 20, 30 };
	int a = 100;
	int (*p)[3] = &ary;

	printf("sizeof(p) = %d\n", sizeof(p));
	printf("sizeof(*p) = %d\n", sizeof(*p));

	my_func1(ary);
	my_func2(ary);
}

void f07_extra3(void) {
	int ary[3] = { 10,20,30 };
	int (*p)[3] = &ary;
	for (int i = 0; i < sizeof(*p) / sizeof(**p); i++) {
		printf("ary[%d] = %d\n", i, *(*p + i));
	}
}

void f07_extra(void) {
	int ary[5] = { 10,20,30,40,50 };
	printf("sizeof(ary) = %d\n", sizeof(ary));
	printf("sizeof(&ary) = %d\n", sizeof(&ary));
	printf("sizeof(ary+1) = 5d\n", sizeof(ary + 1)); //4가 나오는데 ary + 1가 포인터 변수 취급되기 때문이다.
}

void f07_extra2(void) {
	int ary[3][5] = { 0 };
	int (*p)[5] = ary;
	printf("sizeof(ary) = %d\n", sizeof(ary)); //60
	printf("sizeof(ary[0]) = %d\n", sizeof(ary[0])); //20
	printf("sizeof(ary[0][0]) = 5d\n", sizeof(ary[0][0])); //4
	printf("sizeof(*ary) = %d\n", sizeof(*ary)); //20 왜냐면 ary = &ary[0] 이기 때문
	printf("sizeof(p) = %d\n", sizeof(p)); //4
	printf("sizeof(*p) = %d\n", sizeof(*p)); //20
}