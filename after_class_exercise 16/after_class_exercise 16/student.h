#ifndef STUDENT_H
#define STUDENT_H
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define len 20
struct student
{
char name[len];
char ID[len];
int score;
struct student *pNext;
};
extern int number;
FILE * fp;
struct student * s_input(void);
void f_input(void);
void f_output(void);
#endif