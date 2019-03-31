#include "calculation.h"

int Plus(int Pop1, int Pop2) {
	return Pop1 + Pop2;
}

int Minus(int Pop1, int Pop2) {
	return Pop1 - Pop2;
}

int Times(int Pop1, int Pop2) {
	return Pop1 * Pop2;
}

int Divide(int Pop1, int Pop2) {
	return Pop1 / Pop2;
}

int Var_Produce(char* Data, int* Var_count, int* Var_Number, int Blanket) {
	char Dummy[8] = { 0 };
	int i = 0;
	if (Blanket == 1 && *Var_count == 0) for (int j = 1; j < Var_Number[*Var_count]; j++) Dummy[i++] = Data[j];
	else if (*Var_count == 0) for (int j = 0; j < Var_Number[*Var_count]; j++) Dummy[i++] = Data[j];
	else for (int j = Var_Number[*Var_count - 1]; j < Var_Number[*Var_count]; j++) Dummy[i++] = Data[j];
	return atoi(Dummy);
}

void Calculation() {
	char Stack[STACKSIZE] = { 0 };
	char Data[32] = { 0 };
	char Data_OUTPUT[32] = { 0 };
	char Blanket_OUTPUT[16] = { 0 };
	int top = 0;
	int count = 0;
	int Var_count = 0;
	int CData_OUTPUT = 0;
	int Blanket = 0;
	int CStack[STACKSIZE] = { 0 };
	int Var[16] = { 0 };
	int Var_Number[16] = { 0 };
	system("cls");
	puts("중위표기식을 입력해주세요.");
	scanf_s("%s", Data, 32);
	for (int i = 0; Data[i]; i++) {
		
		Var_Number[Var_count]++;
		if (Data[i] == '+' || Data[i] == '-'
			|| Data[i] == '*' || Data[i] == '/') {
			if (Stack[top - 1] && top != 0)  
				for (int j = top - 1; Priority(Stack[j]) >= Priority(Data[i]); j--) Data_OUTPUT[count++] = Pop(Stack, &top);
			Push(Stack, &top, Data[i]);
			Var_Number[Var_count]--;
			Var[Var_count++] = Var_Produce(Data, &Var_count, Var_Number, Blanket);
			Var_Number[Var_count - 1]++;
			Var_Number[Var_count] = Var_Number[Var_count - 1];                                      // 연산자 제외
		}
		else if (Data[i] == '(') {
			if (Var_count == 0) Blanket = 1;
			else Var_Number[Var_count - 1]++;                                                       // ( 제외
			CBlanket(Data, Blanket_OUTPUT, &i, Var, &Var_count, Var_Number, Blanket);
			Var_Number[Var_count]++;                                                                // ) 제외
			for (int j = 0; Blanket_OUTPUT[j]; j++) Data_OUTPUT[count++] = Blanket_OUTPUT[j];
		}
		else Data_OUTPUT[count++] = Data[i];
	}
	Var[Var_count] = Var_Produce(Data, &Var_count, Var_Number, Blanket);
	for (; top > 0;)
		Data_OUTPUT[count++] = Pop(Stack, &top);
	count = 0;
	for (int i = 0; Data_OUTPUT[i]; i++) 
		switch (Data_OUTPUT[i]) {
		case'+': CPush(CStack, &top, Plus(CPop(CStack, &top), CPop(CStack, &top))); break;
		case'-': CPush(CStack, &top, Minus(CPop(CStack, &top), CPop(CStack, &top))); break;
		case'*': CPush(CStack, &top, Times(CPop(CStack, &top), CPop(CStack, &top))); break;
		case'/': CPush(CStack, &top, Divide(CPop(CStack, &top), CPop(CStack, &top))); break;
		default: CPush(CStack, &top, Var[count++]); break;
		}
	CData_OUTPUT = CPop(CStack, &top);
	puts("후위표기식은 ");
	printf("%s\n", Data_OUTPUT);
	puts("계산결과는");
	printf("%d\n", CData_OUTPUT);
	system("pause");
	return;
}