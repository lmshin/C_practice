


void exchange1(int **ap, int** bp) { //ap,bp의 변수의 주소를 전달 받아, a,b 값을 교환하는 함수
	int temp = **ap;
	**ap = **bp;
	**bp = temp;
}

void exchange2(int ***app, int ***bpp) { //app,bpp의 변수의 주소를 전달 받아, a,b 값을 교환하는 함수
	int temp = ***app;
	***app = ***bpp;
	***app = ***bpp;
	***bpp = temp;
}

void exchange3(int** ap, int** bp) { //ap,bp의 변수의 주소를 전달 받아, ap,bp 값을 교환하는 함수
	int* temp = *ap;
	*ap = *bp;
	*bp = temp;
}

void exchange4(int*** app, int*** bpp) { //app,bpp의 변수의 주소를 전달 받아, ap,bp 값을 교환하는 함수
	int* temp = **app;
	**app = **bpp;
	**bpp = temp;
}

void exchange5(int*** app, int*** bpp) { //app,bpp의 변수의 주소를 전달 받아, app,bpp 값을 교환하는 함수
	int** temp = *app;
	*app = *bpp;
	*bpp = temp;
}

void f_13_3() {

	int a = 1, b = 2;
	int* ap = &a, * bp = &b;
	int** app = &ap, ** bpp = &bp;

	printf("a : %d , b : %d\n", a, b);
	printf("ap : %p , bp : %p\n", ap, bp);
	printf("app : %p , bpp : %p\n", app, bpp);
	exchange1(&ap, &bp);
	printf("a : %d , b : %d\n", a, b);
	printf("ap : %p , bp : %p\n", ap, bp);
	printf("app : %p , bpp : %p\n", app, bpp);
	exchange2(&app, &bpp);
	printf("a : %d , b : %d\n", a, b);
	printf("ap : %p , bp : %p\n", ap, bp);
	printf("app : %p , bpp : %p\n", app, bpp);
	exchange3(&ap, &bp);
	printf("a : %d , b : %d\n", a, b);
	printf("ap : %p , bp : %p\n", ap, bp);
	printf("app : %p , bpp : %p\n", app, bpp);
	exchange4(&app, &bpp);
	printf("a : %d , b : %d\n", a, b);
	printf("ap : %p , bp : %p\n", ap, bp);
	printf("app : %p , bpp : %p\n", app, bpp);
	exchange5(&app, &bpp);
	printf("a : %d , b : %d\n", a, b);
	printf("ap : %p , bp : %p\n", ap, bp);
	printf("app : %p , bpp : %p\n", app, bpp);
}


int sum(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int div(int a, int b) {
	return a / b;
}

void f14_1() {
	
	struct opration {
		int (*func)(int, int);
		char* name;

	};

	struct opration myop[] = {
		{sum,"sum"},
		{sub,"sub"},
		{mul,"mul"},
		{div,"div"}
	};

	int a = 10, b = 20;
	int res[4] = { 0 };
	int tot = 0;

	int (*p[])(int, int) = { sum, sub, mul, div };

	//반복문을 사용해서 작성
	for (int i = 0; i < 4; i++) {
		res[i] = p[i](a, b);
		printf("res[i] : % d\n", res[i]);
		tot += res[i];
	}
	printf("tot : %d ", tot);
}

void print_ary(int* ary, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", ary[i]);
	}
	printf("%c",'\n');
}

int comp_asc(int a, int b) {
	return a > b;
}

int comp_dsc(int a, int b) {
	return a < b;
}

void sort_ary(int *ary, int size, int (*comp)(int, int)) {
	int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (comp(ary[i], ary[j])) {
				temp = ary[i];
				ary[i] = ary[j];
				ary[j] = temp;
			}
		}
	}
}

void sort_ary2(int* ary, int size, int order) {
	int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (order == 1) {
				if (ary[i] > ary[j]) {
					temp = ary[i];
					ary[i] = ary[j];
					ary[j] = temp;
				}
			}
			else {
				if (ary[i] < ary[j]) {
					temp = ary[i];
					ary[i] = ary[j];
					ary[j] = temp;
				}
			}
			
		}
	}
}

void f_14_6() {
	int ary[10] = { 2,4,8,6,5,7,1,3,9,0 };
	print_ary(ary,10);
	sort_ary(ary, 10, comp_asc);
	print_ary(ary, 10);
	sort_ary(ary, 10, comp_dsc);
	print_ary(ary, 10);
}

int (*get_func(int num))(int, int) {
	if (num == 0) {
		return sum;
	}
}

void swap_pointer(void* a, void* b, int size) {
	char temp;
	char* ta = (char *)a;
	char* tb = (char *)b;
	for (int i = 0; i < size; i++) {
		temp = ta[i];
		ta[i] = tb[i];
		tb[i] = temp;
	}
}

void f14_9() {
	int ia = 10, ib = 20;
	char ca = 'A', cb = 'B';
	double da = 3.14, db = 0.125;
	printf("%c %c %d %d %.3f %.3f\n", ca, cb, ia, ib, da, db);
	swap_pointer(&ia, &ib,sizeof(int));
	swap_pointer(&ca, &cb, sizeof(char));
	swap_pointer(&da, &db, sizeof(double));
	printf("%c %c %d %d %.3f %.3f\n", ca, cb, ia, ib, da, db);

}

#include <stdio.h>
int compInt(const void* a, const void* b) {
	//return *(const int*)a - *(const int*)b; 이렇게 하면 overflow 발생 가능
	int aa = *(int*)a;
	int bb = *(int*)b;
	return (aa > bb) - (aa < bb);
}

int compChar(const void* a, const void* b) {
	return *(const char*)a - *(const char*)b;
}
int compStr(const void* a, const void* b) {
	return strcmp(*(const char**)a, (const char**)b);
}
int compDouble(const void* a, const void* b) {
	double da = *(const double*)a;
	double db = *(const double*)b;
	double eps = 1e-9;

	//if (fabs(da - db) < eps) return 0;
	return (da > db) - (da < db);
}

typedef void (*printFunc)(const void*);

void printArray(void* base, size_t num, size_t size, printFunc print) {
	char* arr = (char*)base;
	for (size_t i = 0; i < num; i++) {
		print(arr + i * size);
	}
	printf("\n");
}


void printInt(const void* elem) {
	printf("%d ", *(const int*)elem);
}

void printDouble(const void* elem) {
	printf("%.2f ", *(const double*)elem);
}

void printChar(const void* elem) {
	printf("%c ", *(const char*)elem);
}

void printStr(const void* elem) {
	printf("%s ", *(const char**)elem);
}

void f14_11() {
	double da[] = { 1.23, 9.11, 5.46, 7.2, 10.5, 2.7 };
	printArray(da, 6, sizeof(double), printDouble);
	qsort(da, 6, sizeof(double), compDouble);
	printArray(da, 6, sizeof(double), printDouble);

	char* str[] = { "dog", "elephant", "cat", "tiger", "lion" };
	printArray(str, 5, sizeof(char*), printStr);
	qsort(str, 5, sizeof(char*), compStr);
	printArray(str, 5, sizeof(char*), printStr);

	int ia[] = { 8, 7, 5, 2, 3 };
	printArray(ia, 5, sizeof(int), printInt);
	qsort(ia, 5, sizeof(int), compInt);
	printArray(ia, 5, sizeof(int), printInt);

	char ca[] = { 'A', 'Z', 'c', 'y', 'X' };
	printArray(ca, 5, sizeof(char), printChar);
	qsort(ca, 5, sizeof(char), compChar);
	printArray(ca, 5, sizeof(char), printChar);

}