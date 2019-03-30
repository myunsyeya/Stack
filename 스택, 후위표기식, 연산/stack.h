#pragma once
#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 10                                // ���ÿ� �� �� �ִ� �����ڴ� �� 10��
#define PLUS 1                                      // ���ϱ��� �켱 ������ 1
#define MINUS 1                                     // ������ �켱 ������ 1
#define TIMES 2                                     // ���ϱ��� �켱 ������ 2
#define DIVIDE 2                                    // �������� �켱 ������ 2
#define ERROR_VALUE 'E'

void Push(char Stack[], int *top, char data);
char Pop(char Stack[], int *top);
int Priority(char data);
void Blanket(char* Data, char* Blanket_Data_OUTPUT, int* i);