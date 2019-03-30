#pragma once
#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 10                                // 스택에 들어갈 수 있는 연산자는 총 10개
#define PLUS 1                                      // 더하기의 우선 순위는 1
#define MINUS 1                                     // 빼기의 우선 순위는 1
#define TIMES 2                                     // 곱하기의 우선 순위는 2
#define DIVIDE 2                                    // 나누기의 우선 순위는 2
#define ERROR_VALUE 'E'

void Push(char Stack[], int *top, char data);
char Pop(char Stack[], int *top);
int Priority(char data);
void Blanket(char* Data, char* Blanket_Data_OUTPUT, int* i);