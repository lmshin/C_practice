#include "day03.h"
#include <stdio.h>
#include <stdbool.h>

////가상의 하드웨어 레지스터
//#define BUTTON_REG (*(volatile uint32_t*)0x40000000)
//#define LEF_REF (*(volatile uint32_t*)0x40000004)
//
////버튼 상태 읽기 함수
//static bool isButtonPressed() {
//	return (BUTTON_REG & 0x1) != 0;
//}


//암호확인 프로그램 재귀사용
void f_02_4i_2(int key) {
	static int count = 0;
	if (count == 3) {
		printf("관리자에게 문의하세요.");
		return;
	}

	if (key == 1357) {
		printf("로그인 성공!");
		return;
	}
	else {
		count++;
		int input_key;
		printf("틀렸습니다. 암호를 다시 입력하세요 : ");
		scanf("%d", &input_key);
		f_02_4i_2(input_key);
	}

	return;
}

void f_02_4i(void) {

	int count = 0;
	bool flag = true;
	int input_key;
	while (count < 3) {
		if (flag) {
			printf("암호를 입력하세요 : ");
			scanf("%d", &input_key);
		}
		else{
			printf("틀렸습니다! 암호를 다시 입력하세요 : ");
			scanf("%d", &input_key);
		}
		

		if (input_key == 1357) {
			printf("로그인 성공!");
			return;
		}
		else{
			flag = false;
			count++;
		}
	}

	printf("암호를 3번 틀리셨습니다. 관리자에게 문의하세요");
}


void f_04_1(void) {
	int ary[5] = { 1,2,3,4,5 };
	int i;
	int size = sizeof(ary) / sizeof(ary[0]);
	for (i = 0; i < size; i++) {
		printf("%d ", ary[i]);
	}

	return;
}

void f_04_5(void) {
	int score[5];
	int i;
	int size = sizeof(score) / sizeof(score[0]);

	int sum = 0;
	for (int i = 0; i < size; i++) {
		printf("%d 번째 학생의 점수를 입력하세요 : ", i+1);
		scanf("%d", *(score + i));
		sum += score[i];
	}

	double avg = (double)sum / size;
	for (int i = 0; i < size; i++) {
		printf("%d 번째 학생의 점수 : %d\n", i+1, score[i]);
	}
	printf("이 학생들의 평균 점수는 %.1lf 입니다.\n", avg);

	return;
}

void swap(int* pa, int* pb) {
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;

	return;
}

void f_05_8(void){
	int a = 10, b = 20;
	int* pa = &a;
	int* pb = &b;
	swap(&a, &b);
	printf("swap: %d %d\n", a, b);
}

void printMemu(void) {
	printf("+--------------------------------------+\n");
	printf("+ 0 : 더하기                           +\n");
	printf("+ 1 : 빼기                             +\n");
	printf("+ 2 : 곱하기                           +\n");
	printf("+ 3 : 나누기                           +\n");
	printf("+ 4 : 종료                             +\n");
	printf("+--------------------------------------+\n");
}

int add(int a, int b) {
	return a + b;
}

int minus(int a, int b) {
	return a - b;
}

int multi(int a, int b) {
	return a * b;
}

int divi(int a, int b) {
	return a / b;
}

void f_fp_exercise(void) {
	int a, b;
	int choice;
	int (*op[])(int, int) = { add,minus,multi,divi };
	scanf("%d %d", &a, &b);
	printMemu();
	scanf("%d", &choice);
	if ((choice >= 0) && (choice <= 4)) {
		printf("%d\n", op[choice](a, b));
	}
}

