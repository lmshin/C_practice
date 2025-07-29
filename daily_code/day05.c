#include "day05.h"
//extern void Increment(); //이렇게 해주는게 정석이지만 함수는 extern을 안써도 된다.
//extern int GetNum();
#include<stdio.h>
extern int num;

char* to_upper(char* name, int size){

	for (int i = 0; i < size; i++) {
		if ('a' <= name[i] && name[i] <= 'z') {
			name[i] = name[i] - ('a' - 'A');
		}
	}
	
	return name;
}

//void print_ary(char* name){
//	int i = 0;
//	while (name[i] != '\n') {
//		printf("%c", name[i]);
//		i++;
//	}
//
//	return;
//}

//char* strcpy(char * from, char * to) { //from을 to에 복사하는 함수
//	char* save = to;
//	for (; (*to = *from); from++, to++);
//	return save;
//}
//
//int strlen(char * str) {
//	const char* s;
//	if (str == 0) return 0;
//
//	for (s=str; *s; s++);
//	return s - str;
//}
//
//void strcat(char* s, const char* append) {
//	char* save = s;
//	for (; *s; s++);
//	while (*s++ = *append++);
//	return save;
//}
//
//int strcmp(char* str1, char* str2) {
//
//	while (*str1 == *str2) {
//		if (*str1 == '\0') return 0;  // 문자열 끝까지 동일하면 0 반환
//		str1++;
//		str2++;
//	}
//
//	return *(unsigned const char*)str1 - *(unsigned const char*)str2;
//}

void f10_10(void) {
	printf("num : %d\n", GetNum()); //0
	Increment();
	printf("num : %d\n", GetNum()); //1
	Increment();
	printf("num : %d\n", GetNum()); //2

	num++;
	printf("main-num : %d\n", GetNum()); //?
	return;
}
//
//void array_pointer_ex2(void) {
//	int a[3][4] = { 0 };
//	int* temp = a[0];
//	(void)freopen("day05.txt", "rt", stdin);
//	for (int i = 0; i < size_ary(a); ++i) {
//		for (int j = 0; j < size_ary(a[0]); ++j) {
//			//(void)scanf("%d", &a[i][j]);
//			//(void)scanf("%d", a[i] + j);
//			//(void)scanf("%d", a[0] + (i * size_ary(a[0]) + j));
//			//(void)scanf("%d", temp + (i * size_ary(a[0]) + j));
//			//(void)scanf("%d", temp++);
//		}
//	}
//	temp = a[0];
//	for (int i = 0; i < size_ary(a) * size_ary(a); ++i) {
//		prinft("3d", temp + i);
//	}
//
//
//	for (int i = 0; i < size_ary(a); ++i) {
//		for (int j = 0; j < size_ary(a[0]); ++j) {
//			printf("%3d ", a[i][j]);
//		}
//		printf("\n");
//	}
//}
