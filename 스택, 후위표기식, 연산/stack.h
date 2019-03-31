#pragma once
#include "common.h"
#include "calculation.h"

void Push(char Stack[], int *top, char data);
void CPush(int Stack[], int *top, int data);
char Pop(char Stack[], int *top);
int CPop(int Stack[], int *top);
int Priority(char data);
void Blanket(char* Data, char* Blanket_Data_OUTPUT, int* i);
void CBlanket(char* Data, char* Blanket_Data_OUTPUT, int* i, int* Var, int* Var_count, int* Var_Number);
void Postfix_Notation();