#include "day03.h"
#include <stdio.h>
#include <stdbool.h>

////������ �ϵ���� ��������
//#define BUTTON_REG (*(volatile uint32_t*)0x40000000)
//#define LEF_REF (*(volatile uint32_t*)0x40000004)
//
////��ư ���� �б� �Լ�
//static bool isButtonPressed() {
//	return (BUTTON_REG & 0x1) != 0;
//}


//��ȣȮ�� ���α׷� ��ͻ��
void f_02_4i_2(int key) {
	static int count = 0;
	if (count == 3) {
		printf("�����ڿ��� �����ϼ���.");
		return;
	}

	if (key == 1357) {
		printf("�α��� ����!");
		return;
	}
	else {
		count++;
		int input_key;
		printf("Ʋ�Ƚ��ϴ�. ��ȣ�� �ٽ� �Է��ϼ��� : ");
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
			printf("��ȣ�� �Է��ϼ��� : ");
			scanf("%d", &input_key);
		}
		else{
			printf("Ʋ�Ƚ��ϴ�! ��ȣ�� �ٽ� �Է��ϼ��� : ");
			scanf("%d", &input_key);
		}
		

		if (input_key == 1357) {
			printf("�α��� ����!");
			return;
		}
		else{
			flag = false;
			count++;
		}
	}

	printf("��ȣ�� 3�� Ʋ���̽��ϴ�. �����ڿ��� �����ϼ���");
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
		printf("%d ��° �л��� ������ �Է��ϼ��� : ", i+1);
		scanf("%d", *(score + i));
		sum += score[i];
	}

	double avg = (double)sum / size;
	for (int i = 0; i < size; i++) {
		printf("%d ��° �л��� ���� : %d\n", i+1, score[i]);
	}
	printf("�� �л����� ��� ������ %.1lf �Դϴ�.\n", avg);

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
	printf("+ 0 : ���ϱ�                           +\n");
	printf("+ 1 : ����                             +\n");
	printf("+ 2 : ���ϱ�                           +\n");
	printf("+ 3 : ������                           +\n");
	printf("+ 4 : ����                             +\n");
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

