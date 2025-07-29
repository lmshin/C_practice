#include "day08.h"
#include <string.h>

void test01() {
	unsigned int size = 100;
	void* ptr = malloc(size);
	printf("sizeof ptr : %d\n", sizeof(ptr)); //100byte 할당

	int arr[10];
	int* p = (int*)malloc(sizeof(int) * sizeof(arr) / sizeof(arr[0])); //4 * 10 이므로 40byte 할당
	printf("sizeof p : %d\n", sizeof(p));
	printf("sizeof *p : %d\n", sizeof(*p));
	printf("sizeof &p : %d\n", sizeof(&p));
}

void f15_1() {
	int* pi;
	double* pd;

	pi = (int*)malloc(sizeof(int) * 10);
	if (pi == NULL) {
		printf("메모리 부족");
		exit(1);
	}

	pd = (double*)malloc(sizeof(double) * 10);
	if (pd == NULL) {
		printf("메모리 부족");
		exit(1);
	}

	free(pi);
	free(pd);
}


double get_average(int sum, int n) {
	return sum / (double)n;
}

void f15_2() {
	int T;
	int n, sum=0;

	freopen("numbers.txt", "rt", stdin);
	(void)scanf("%d", &T);

	while (T--) {
		sum = 0;
		(void)scanf("%d", &n);
		int* arr = (int*)malloc(sizeof(int) * n);
		
		if (arr == NULL) {
			printf("메모리 부족");
			exit(1);
		}

		printf("%d 명의 나이를 입력하세요 :", n);
		for (int i = 0; i < n; i++) {
			scanf("%d", arr+i);
			sum += arr[i];
		}
		printf("\n");
		printf("%d 명의 평균 나이 : %.1lf\n", n, get_average(sum, n));
		free(arr);
		arr = NULL;
	}
}

void f15_2_2() {
	int T;
	int n, sum = 0;
	int n_sum = 0;
	int* arr = NULL;
	freopen("numbers.txt", "rt", stdin);
	(void)scanf("%d", &T);

	while (T--) {
		(void)scanf("%d", &n);
		n_sum += n;

		int* temp = (int*)realloc(arr, sizeof(int) * n_sum);
		
		if (temp == NULL) {
			printf("메모리 부족");
			free(arr);
			exit(1);
		}
		arr = temp;

		//printf("%d 개의 데이터를 입력하세요 :", n);
		for (int i = n_sum - n; i < n_sum; i++) {
			scanf("%d", arr + i);
			sum += arr[i];
		}

		//printf("\narr 주소 : %p\n", arr);
		//printf("\n arr 배열 출력 : ");
		//print_ary(arr, n_sum);
		//printf("\n");

		printf("%d 개 데이터의 평균 : %.1lf\n", n_sum, get_average(sum, n_sum));
	}
	free(arr);
	arr = NULL;
}

static void realloc_test(int** pi, int n, int a, int *psum) {
	int* tmp = NULL;
	tmp = (int*)realloc(*pi, sizeof(int) * (n + a));

	if (tmp == NULL) {
		printf("메모리가 부족합니다");
		exit(1);
	}
	*pi = tmp;

	/*for (int i = n; i < n + a; i++) {
		(void)scanf("%d", *pi + i);
		*psum += *(*pi + i);
	}*/
	 
	int idx = n;
	while (idx < n + a) {
		(void)scanf("%d", tmp + idx);
		*psum += *(*pi + idx++);
	}
}

void f15_2b(void) {
	int T;
	int N = 0;
	int sum = 0;
	int* psum = &sum;
	int* pi = NULL;
	(void)freopen("numbers.txt", "rt", stdin);
	(void)scanf("%d", &T);

	while (T--) {
		int n;
		(void)scanf("%d", &n);
		realloc_test(&pi, N, n, psum);
		N += n;
	}

	printf("%d 명의 평균 나이 : %.1lf \n", N, (double)sum / N);
	free(pi);
	pi = NULL; // 이걸 해주는 이유
}

void print_stringArray(char** str, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s\n", str[i]);
	}
}

void free_str(char** str, int n) {
	for (int i = 0; i < n; i++) {
		free(str[i]);
	}
	free(str);
}

char** get_stringArray(int n) {
	char** str;
	char temp[80] = { 0 };
	
	str = (char**)calloc(n, sizeof(char*));
	if (str == NULL) {
		return NULL;
	}
	while (getchar() != '\n');

	for (int i = 0; i < n; i++) {
		fgets(temp,sizeof(temp),stdin);
		temp[strlen(temp) - 1] = '\0';

		str[i] = (char*)calloc(strlen(temp) + 1, sizeof(char));
		if (str[i] == NULL) {
			printf("메모리가 부족합니다.");
			free_str(str, i);
			return NULL;
		}
		strcpy(str[i], temp);
	}

	return str;
}

void f15_7() {
	//입력 주소로부터 \0이 등장할 때까지 입력을 받는다?
	FILE *fp = freopen("data.txt", "rt", stdin);
	if (fp == NULL) {
		
	}

	int n;
	scanf("%d", &n);

	char** str = get_stringArray(n);
	print_stringArray(str, n);

	fclose(fp);
	free_str(str,n);
}

int* return_array() {
	static int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	return *a;
}
void f15_9() {
	int *p = return_array();
	for (int i = 0; i < 10; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");
}
//scanf("s",str) 공백이 나오기 전까지의 문자열을 입력받고 \0 을 추가
//gets(str) Enter가 나오기 전까지의 문자열을 입력받고 \0 을 추가
//fget(str,sizeof(str),stdin) 개행문자까지 문자열에 저장하고 마지막에 널문자(\0) 추가

struct profile {
	int age;
	double height;
	char* name;
};

typedef struct _profile {
	int age;
	double height;
	char* name;
} profile_t;

static void init_struct(profile_t* pf) {
	pf->age = 21;
	pf->height = 160;
	pf->name = "윤소영";
}

static void print_struct(profile_t s) {
	printf("나이 : %d\n", s.age);
	printf("키 : %.1lf\n", s.height);
	printf("이름 : %s\n", s.name);
}

void f16_8() {
	profile_t pf = { 0 };
	init_struct(&pf);
	print_struct(pf);

}