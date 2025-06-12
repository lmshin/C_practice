#include "day08.h"

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
	int* arr = 0;
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
		////0 10 15
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


