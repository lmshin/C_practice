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