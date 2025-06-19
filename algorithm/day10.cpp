#if 01
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX 25

int visited[MAX + 2][MAX + 2];
int houseMap[MAX + 2][MAX + 2];
int houseCountInd[MAX * MAX / 2 + 1];
int curInd = 0;
int direct[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int N;

enum Direction {
	UP = 0,
	DOWN,
	RIGHT,
	LEFT
};

enum dimension {
	Y=0,
	X
};

static int compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	if (*(int*)first < *(int*)second)
		return -1;
	return 0;
}

void eraseEnter() {
	while (getchar() != '\n');
}

void inputData() {
	char s[MAX] = { 0, };
	(void)scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%s", s + 1);
		int* pTmp = houseMap[i];
		for (int j = 1; j <= N; j++) {
			pTmp[j] = s[j] - 48;
		}
	}
}

void doRecursive(int x, int y) {
	if (houseMap[y][x] != 1) return;

	houseCountInd[curInd] += 1;
	houseMap[y][x] = -1;

	doRecursive(x + direct[UP][X], y + direct[UP][Y]);
	doRecursive(x + direct[DOWN][X], y + direct[UP][Y]);
	doRecursive(x + direct[RIGHT][X], y + direct[RIGHT][Y]);
	doRecursive(x + direct[LEFT][X], y + direct[LEFT][Y]);
}

static void updateHouseCount(int x, int y) {
	houseCountInd[curInd] += 1;
	houseMap[y][x] = -1;

	doRecursive(x + direct[DOWN][X], y + direct[DOWN][Y]);
	doRecursive(x + direct[RIGHT][X], y + direct[RIGHT][Y]);
}

void danji_01(void) {
	inputData();

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (houseMap[y][x] == 1) {
				updateHouseCount(x, y);
				curInd++;
			}
		}
	}

	return;
}
#endif

#if 02
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int** graph;
int* answer;

int nx[4] = { 0,1,0,-1 };
int ny[4] = { 1,0,-1,0 };

void memRelease() {
	free(graph);
	free(answer);
}

int dfs(int x, int y) {
	int ans = 1;
	graph[y][x] = 2;

	int next_x, next_y;
	for (int i = 0; i < 4; i++) {
		next_x = x + nx[i];
		next_y = y + ny[i];

		if (graph[next_y][next_y] == 1) {
			ans += dfs(next_y, next_y);
		}
	}

	return ans;
}
//
//int main() {
//	//map 할당
//	int** graph = (int**)malloc(sizeof(int*) * (MAX + 2));
//	int* temp = (int*)calloc((MAX + 2) * (MAX + 2), sizeof(int));
//	if (temp == NULL) {
//		free(graph);
//		exit(1);
//	}
//
//	for (int i = 0; i < N + 2; i++) {
//		graph[i] = (MAX + 2) * i + temp;
//	}
//
//	//입력
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			scanf("%1d", graph[i][j]);
//		}
//	}
//	//dfs
//	int size = 0;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			if (graph[i][j] == 1) {
//				answer = (int*)realloc(answer, (++size) * sizeof(int));
//				if (answer == NULL) {
//					memRelease();
//					exit(1);
//				}
//				answer[size - 1] = dfs(i, j);
//			}
//		}
//	}
//
//
//	//출력
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			printf("%d", graph[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

#endif