#include "day09.h"

void alloc_ex01() {
	int n = 10;
	
	//int** a = (int**)calloc(n, sizeof(int(*)[100])); //문법도 틀리고, 배열 처럼 접근이 안되기 때문에 폐기!
	typedef int a_i100_t[100];
	typedef a_i100_t arr;

	int(*p)[100] = (int (*)[100])calloc(n, sizeof(int[100]));

	//x
	/*int** a = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		a[i] = (int*)calloc(100, sizeof(int));
	}*/

	if(p == NULL) {
		printf("할당 실패!");
		exit(1);
	}

	/*printf("a : %d\n", sizeof(a));
	printf("a[0] : %d\n", sizeof(a[0]));
	printf("a[0][0] : %d\n", sizeof(a[0][0]));

	int arr[10][100];
	printf("arr : %d\n", sizeof(arr));
	printf("arr[0] : %d\n", sizeof(arr[0]));
	printf("arr[0][0] : %d\n", sizeof(arr[0][0]));

	free_array(a, n);*/
}

void alloc_ex02() {
	//int a[4][3][5];
	int n = 4;
	int (*p)[3][5] = (int(*)[3][5])calloc(n, sizeof(int[3][5]));

	if (p == NULL) {
		printf("할당실패!\n");
		exit(1);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 5; k++) {
				p[i][j][k] = ++cnt;
				printf("%d ", cnt);
			}
			printf("\n");
		}
		printf("\n");
	}

	free(p);
	p = NULL;
}


void free_array(int** a, int size) {
	for (int i = 0; i < size; i++) {
		free(a[i]);
	}

	free(a);
}

void alloc_ex03() {
	int n;
	int arr_size;
	
	FILE *fp = freopen("alloc_data.txt", "rt", stdin);

	scanf("%d", &n);
	int** p = (int**)calloc(n, sizeof(int*));

	if (p == NULL) {
		printf("할당실패!\n");
		exit(1);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr_size);
		p[i] = (int*)calloc(arr_size + 1 , sizeof(int));
		if (p[i] == NULL) {
			printf("할당실패!\n");
			exit(1);
		}

		p[i][0] = arr_size;
		for (int j = 0; j < arr_size; j++) {
			scanf("%d", &p[i][j + 1]);
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= p[i][0]; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	printf("\n\n\n");
	printf("p : %d\n", sizeof(p));
	printf("p[0] : %d\n", sizeof(p[0]));
	printf("p[0][0] : %d\n", sizeof(p[0][0]));

	fclose(fp);
	free_array(p, n);
}

void alloc_ex04() {
	int n, m;
	scanf("%d %d", &n, &m);

	/*int** p = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		p[i] = (int*)calloc(m, sizeof(int));
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			p[i][j] = ++cnt;
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}*/

	int cnt = 0;
	int* p = (int*)calloc(n*m, sizeof(int));
	int** arr = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		arr[i] = &p[i * m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = ++cnt;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	//해제
	free(p);
	free(arr);
}

typedef struct student {
	int id;
	int scores[3];
	char name[20];
} my_student;


void input_data(my_student* arr, int n) {
	int id, scores[3], score;
	char name[20];
	/*for (int i = 0; i < n; i++) {
		scanf("%d", &id);
		scanf("%d", scores + 0);
		scanf("%d", scores + 1);
		scanf("%d", scores + 2);
		scanf("%s", name);
		
		arr[i].id = id;
		arr[i].scores[0] = scores[0];
		arr[i].scores[1] = scores[1];
		arr[i].scores[2] = scores[2];
		strcpy(arr[i].name, name);
	}*/

	for (int i = 0; i < n; i++) {
		scanf("%d", &(arr + i)->id);
		scanf("%d", &(arr + i)->scores[0]);
		scanf("%d", &(arr + i)->scores[1]);
		scanf("%d", &(arr + i)->scores[2]);
		scanf("%s", &(arr + i)->name);
	}
}

void print_data(my_student* arr, int n) {

	for (int i = 0; i < n; i++) {
		printf("id: %d\n", arr[i].id);
		printf("score 1: %d\n", arr[i].scores[0]);
		printf("score 2: %d\n", arr[i].scores[1]);
		printf("score 3: %d\n", arr[i].scores[2]);
		printf("student'name : %s\n", arr[i].name);
	}
}

void f16_9() {
	//student 배열의 크기를 동적으로 할당받아서 사용해보자
	FILE* fp = freopen("student.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	
	my_student* arr = (my_student*)calloc(n, sizeof(my_student));
	if (arr == NULL) {
		printf("메모리 할당 error");
		exit(1);
	}

	input_data(arr, n);
	print_data(arr, n);

	fclose(fp);
	free(arr);
	arr = NULL;
}

typedef struct rgb {
	unsigned short blue : 5;
	unsigned short green : 6;
	unsigned short red : 5;
} RGB_t;

typedef union pixelcolor {
	RGB_t rgb;
	unsigned short color;
} PColor_t;

void f17_03(void) {
	PColor_t dot1 = { 0 }, dot2 = { 0 };
	dot1.color = 0x1234;
	printf("%d %d\n", sizeof(RGB_t), sizeof(PColor_t));
	printf("%#x\n", dot1.color);
	printf("%d %d %d\n", dot1.rgb.red, dot1.rgb.green, dot1.rgb.blue);
	
}

//만들고 싶은 것 double (*selectFunc(char ch))(int, double); 
typedef double(*FP)(int, double);
FP SelectFunc(char ch);

double func_a(int a, double b) {
	return a * b;
}

double func_b(int a, double b) {
	return a / b;
}

FP SelectFunc(char ch) {
	if (ch == 'a') return func_a;
	return func_b;
}

void typedef_ex01(void) {
	FP myfunc = SelectFunc('a');
	printf("%.1f\n", myfunc(10, 2.5));
}



//만들고 싶은 것 int (*SelectArray(int what))[4]

typedef int (*AP)[4]; //크기가 4인 int 포인터 배열 의 별칭을 AP로 지정
AP SelectArray(int what);

AP SelectArray(int what){

	static int arr[3][4] = { 0 };
	return arr;

}

void typedef_ex02(void) {
	AP ap = SelectArray(0);
	printf("%d", ap[1][2]);
}


// 구조체 멤버 접근
struct Point {
	int x, y;
};

#define GET_MEMBER(p, m) p##.##m
void f_pre01(void) {
	struct Point pt = { 1, 2 };
	printf("%d\n", GET_MEMBER(pt, y));  // → pt.y → 2
}

// 변수 추적 매크로
#define DEBUG_VAR(var) printf("[DEBUG] %s = %d (in %s:%d)\n", #var, var, __FILE__, __LINE__)
void f_pre02(void) {
	int score = 80;
	DEBUG_VAR(score);
}

// 자동 변수 이름 생성
#define DECLARE_INT(name) int var_##name
#define SET_VALUE(name, val) var_##name = val
#define PRINT_VALUE(name) printf(#name " = %d\n", var_##name)

void f_pre03(void) {
	DECLARE_INT(score);
	SET_VALUE(score, 90);
	PRINT_VALUE(score);
}