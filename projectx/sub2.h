#ifndef __SUB2_H_
#define __SUB2_H_

#include <stdio.h>
#define MAX 10

void func_sub2(struct student* ap);

typedef int* IP;
int a;
struct student {
	char name[20];
	int score;
};

#endif