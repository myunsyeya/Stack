#include "calculation.h"

void Calculation() {
	char Stack[STACKSIZE] = { 0 };
	char Data[32] = { 0 };
	char Data_OUTPUT[32] = { 0 };
	char Blanket_OUTPUT[16] = { 0 };
	int top = 0;
	int count = 0;
	int Var[16] = { 0 };
	int Var_Number[16] = { 0 };
	system("cls");
	puts("중위표기식을 입력해주세요.");
	scanf_s("%s", Data, 32);
	for (int i = 0; Data[i]; i++) {

		if (Data[i] == '+' || Data[i] == '-'
			|| Data[i] == '*' || Data[i] == '/') {
			if (Stack[top - 1] && top != 0)  
				for (int j = top - 1; Priority(Stack[j]) >= Priority(Data[i]); j--) Data_OUTPUT[count++] = Pop(Stack, &top);
			Push(Stack, &top, Data[i]);
		}
		else if (Data[i] == '(') {
			Blanket(Data, Blanket_OUTPUT, &i);
			for (int j = 0; Blanket_OUTPUT[j]; j++) Data_OUTPUT[count++] = Blanket_OUTPUT[j];
		}
		else Data_OUTPUT[count++] = Data[i];
	}
	for (; top > 0;)
		Data_OUTPUT[count++] = Pop(Stack, &top);
	puts("후위표기식은 ");
	printf("%s\n", Data_OUTPUT);
	system("pause");
	return;
}