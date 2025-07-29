#include "day02.h"

void f_01_10j(void) {
	
	int a = 10, b = 20, res;
	res = (a > b) ? a : b;

	if (a > b) {
		res = a;
	}
	else {
		res = b;
	}
	
	printf("큰 값 : %d\n", res);
}

void f_01_10n(void) {
	unsigned int num = 0b1010;
	printf("Inital Value : %X\n", num);
	printf("After setBit : %X\n", setBit(num,2));
	printf("After clearBit : %X\n", clearBit(num,1));
	printf("After toggleBit : %X\n", toggleBit(num,3));
}

void f_01_10o(void) {
	unsigned int num = 0b1010;
	printf("Inital Value : %X\n", num);
	printf("After setBit : %X\n", setBits(num, 2, 3));
	printf("After clearBit : %X\n", clearBits(num, 4, 2));
	printf("After toggleBit : %X\n", toggleBits(num, 1, 5));
}

void f_01_10q(void) {
	int number, bitPosition;

	printf("Enter a number: ");
	scanf("%d", &number);

	printf("Enter bit position to check: ");
	scanf("%d", &bitPosition);

	unsigned int result = isBitSet(number, bitPosition);
	printf("Bit %u of number %u is %u", bitPosition, number, result);
}

void f_01_11b(void) {
	int num;
	printf("뒤집을 number를 입력하세요 : ");
	scanf("%d", &num);

	printf("%d\n", reverseNumber(num));
}

void f_01_11e(void) {
	int a = 10, b;
	float f = 3.14f;

	a++;
	f++;
	printf("%d, %f\n", a, f);

	++a;
	++f;
	printf("%d, %f\n", a, f);
}

void f_01_11f(void) {
	int a = 0x33CC33CC;
	//a변수의 0,5,21,22번 비트를 set,clear,toggle 하는 코드
	a |= (1 << 0) | (1 << 5) | (3 << 21);
	a &= ~((1 << 0) | (1 << 5) | (3 << 21));
	a ^= (1 << 0) | (1 << 5) | (3 << 21);
}

void f_01_03a(void) {
	unsigned char a = 0xf0;
	char b = 0xf0;
	unsigned char c = 0x0f;
	char d = 0x0f;

}

void f_02_2d() {
	int num;
	printf("정수를 입력하세요 : ");
	scanf("%d", &num);
}

int reverseNumber(int num) {
	int reverse_num = 0;
	int sign = (num < 0) ? -1 : 1;

	num *= sign;

	while (num) {
		reverse_num *= 10;
		reverse_num += num % 10;
		num /= 10;
	}

	return reverse_num * sign;
}

unsigned int setBit(unsigned int num, int bitPosition) {

	unsigned int mask = 1U << bitPosition;
	return num | mask;
}

unsigned int clearBit(unsigned int num, int bitPosition) {

	unsigned int mask = 1U << bitPosition;
	unsigned int cleared_mask = ~mask;
	return num & cleared_mask;
}

unsigned int toggleBit(unsigned int num, int bitPosition) {

	unsigned int mask = 1U << bitPosition;
	return num ^ mask;

}

unsigned int setBits(int num, int start, int count) {
	unsigned int mask = (1 << count) - 1;
	mask <<= start;
	return num | mask;
}

unsigned int clearBits(int num, int start, int count) {
	unsigned int mask = (1 << count) - 1;
	mask <<= start;
	return num & ~mask;
}

unsigned int toggleBits(int num, int start, int count) {
	unsigned int mask = (1 << count) - 1;
	mask <<= start;
	return num ^ mask;
}

static unsigned int isBitSet(unsigned int num, int bitPosition) {

	unsigned int mask = (1 << bitPosition);
	unsigned int result = (num & mask) ? 1 : 0;

	return result;
}

static unsigned int isBitSet2(unsigned int num, int bitPosition) {
	if (num & (1 << bitPosition)) return 1;
	else return 0;
}

