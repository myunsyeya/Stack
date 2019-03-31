#include "stack.h"

void Push(char Stack[], int *top, char data) {       // 스택에 연산자가 차곡 차곡 쌓이는 과정
	if (*top == STACKSIZE) {                         // 연산자가 10개 들어갔으면,
		puts("더 이상 연산자를 출력할 수 없습니다.");
		return;
	}
	Stack[(*top)++] = data;
}

char Pop(char Stack[], int *top) {                    // 탑에서 연산자를 하나씩 빼오는 과정
	if (*top == 0) {                                  // 연산자가 더 이상 없다면(탑이 비었다면),
		puts("End.");
		return ERROR_VALUE;
	}
	return Stack[--*top];
}

int Priority(char data) {                             // 우선순위를 비교해주는 과정
	switch (data)
	{
	case '+': return PLUS; break;
	case '-': return MINUS; break;
	case '*': return TIMES; break;
	case '/': return DIVIDE; break;
	}
	return 0;
}

void Blanket(char* Data, char* Blanket_Data_OUTPUT, int* i) {
	char Stack[STACKSIZE] = { 0 };
	char Blanket_Data[16] = { 0 };
	int top = 0;
	int count = 0;
	for ((*i)++; Data[*i] != ')'; (*i)++) {
		if (Data[*i] == '+' || Data[*i] == '-'
			|| Data[*i] == '*' || Data[*i] == '/') {
			if (Stack[top - 1] && top != 0)
				for (int j = top - 1; Priority(Stack[j]) >= Priority(Data[*i]); j--)
					Blanket_Data_OUTPUT[count++] = Pop(Stack, &top);
			Push(Stack, &top, Data[*i]);
		}
		else if (Data[*i] == '(') {
			Blanket(Data, Blanket_Data, i);
			for (int j = 0; Blanket_Data[j]; j++) Blanket_Data_OUTPUT[count++] = Blanket_Data[j];
		}
		else Blanket_Data_OUTPUT[count++] = Data[*i];
	}
	for (; top > 0;)
		Blanket_Data_OUTPUT[count++] = Pop(Stack, &top);
}