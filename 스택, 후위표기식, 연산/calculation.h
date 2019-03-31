#pragma once
#include "stack.h"

int Plus(int Pop2, int Pop1);
int Minus(int Pop2, int Pop1);
int Times(int Pop2, int Pop1);
int Divide(int Pop2, int Pop1);
int Var_Produce(char* Data, int* Var_count, int* Var_Number, int Blanket);
void Calculation();