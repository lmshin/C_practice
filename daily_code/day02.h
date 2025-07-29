#ifndef __DAY02_H__
#define __DAY02_H__

#include<stdio.h>
void f_01_10j(void);
void f_01_10n(void);
void f_01_10o(void);
void f_01_10q(void);
void f_01_11b(void);
void f_01_11e(void);
unsigned int setBit(unsigned int num, int bitPosition);
unsigned int clearBit(unsigned int num, int bitPosition);
unsigned int toggleBit(unsigned int num, int bitPosition);
unsigned int setBits(unsigned int num, int start, int count);
unsigned int clearBits(unsigned int num, int start, int count);
unsigned int toggleBits(unsigned int num, int start, int count);
static unsigned int isBitSet(unsigned int num, int bitPosition);
#endif