#include <stdio.h>

void f_01_7(void) {
	unsigned char uch1 = -1; // 1111 1111
	unsigned char uch2 = 128; //1000 0000
	signed char ch1 = -1;
	signed char ch2 = 128;

	printf("unsigned char(%%u) : %u %u\n", uch1, uch2); 
	printf("signed char(%%d) : %d %d\n", ch1, ch2);

	printf("signed char(%%d) : %d %d\n", uch1, uch2);
	printf("unsigned char(%%u) : %u %u\n", ch1, ch2);
}

void f_01_10d() {
	int a = 10;
	int b = 10;
	++a;
	--b;
	printf("a : %d\n",a);
	printf("b : %d\n", b);

	int pre = (++a) * 3;
	int post = (b++) * 3;

	printf("a=%d, b=%d\n", a, b);
	printf("pre=%d, post=%d\n",pre, post);
}

void f_01_7f(void) {
	int num = 10;
	int* p = &num;

	printf("%zu %zu\n", sizeof(num), sizeof(p));
	printf("%p %p\n", p, &num);
	printf("%d %d\n", *p, num);
	printf("%p %d\n", &p, **&p);
}

void f_01_10f(void) {
	int a = 10, b = 20, c = 10;
	int res[7] = { 0 };

	res[0] = (a > b);
	res[1] = (a >= b);
	res[2] = (a < b);
	res[3] = (a <= b);
	res[4] = (a <= c);
	res[5] = (a == b);
	res[6] = (a != c);

	for (int i = 0; i < 7; i++) {
		printf("res[%d] = %d\n", i, res[i]);
	}
}	

//short-circuit 사용 예제,
//포인터가 NULL인지 확인후, 포인터를 참조하도록 하여 안전하게 사용한다.
void f_01_10i(void) {
	int a = 9;
	int* ptr = &a;
	if (ptr != NULL && *ptr == 10) {
		//ptr이 NULL이 아니고 *ptr이 10인 경우 실행

	}
}
//배열 인덱스 유효성을 검사한다. 조건문으로 미리 처리한다.
void printArrayElement(int* array, int size, int index) {
	if (index >= 0 && index < size && array[index] == 10) {
		printf("Element at index %d is 10\n", index);
	}
}

int main() {
	f_01_7();
	f_01_7f();
	f_01_10d();
	f_01_10f();
}

//문제를 풀고 설명할 수 있어야함!
