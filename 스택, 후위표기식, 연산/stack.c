#include "stack.h"

void Push(char Stack[], int *top, char data) {       // ���ÿ� �����ڰ� ���� ���� ���̴� ����
	if (*top == STACKSIZE) {                         // �����ڰ� 10�� ������,
		puts("�� �̻� �����ڸ� ����� �� �����ϴ�.");
		return;
	}
	Stack[(*top)++] = data;
}

char Pop(char Stack[], int *top) {                    // ž���� �����ڸ� �ϳ��� ������ ����
	if (*top == 0) {                                  // �����ڰ� �� �̻� ���ٸ�(ž�� ����ٸ�),
		puts("End.");
		return ERROR_VALUE;
	}
	return Stack[--*top];
}

int Priority(char data) {                             // �켱������ �����ִ� ����
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
		else Blanket_Data_OUTPUT[count++] = Data[*i];
	}
	for (; top > 0;)
		Blanket_Data_OUTPUT[count++] = Pop(Stack, &top);
}