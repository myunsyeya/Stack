#pragma once
#include "common.h"

void Push(char Stack[], int *top, char data);
char Pop(char Stack[], int *top);
int Priority(char data);
void Blanket(char* Data, char* Blanket_Data_OUTPUT, int* i);
void Postfix_Notation();