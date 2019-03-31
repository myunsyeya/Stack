#include "stack.h"

void Push(char Stack[], int *top, char data) {       // ���ÿ� �����ڰ� ���� ���� ���̴� ����
	if (*top == STACKSIZE) {                         // �����ڰ� 10�� ������,
		puts("�� �̻� �����ڸ� ����� �� �����ϴ�.");
		return;
	}
	Stack[(*top)++] = data;
}

void CPush(int Stack[], int *top, int data) {
	if (*top == STACKSIZE) {
		puts("�� �̻� �����ڸ� ����� �� �����ϴ�.");
		return;
	}
	Stack[(*top)++] = data;
}

char Pop(char Stack[], int *top) {                    // ž���� �����ڸ� �ϳ��� ������ ����
	if (*top == 0) return ERROR_VALUE;                // �����ڰ� �� �̻� ���ٸ�(ž�� ����ٸ�)
	return Stack[--*top];
}

int CPop(int Stack[], int *top) {
	if (*top == 0) return 0;
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

void CBlanket(char* Data, char* Blanket_Data_OUTPUT, int* i, int* Var, int* Var_count, int* Var_Number, int Blanket) {
	char Stack[STACKSIZE] = { 0 };
	char Blanket_Data[16] = { 0 };
	int top = 0;
	int count = 0;
	for ((*i)++; Data[*i] != ')'; (*i)++) {
		Var_Number[*Var_count]++;
		if (Data[*i] == '+' || Data[*i] == '-'
			|| Data[*i] == '*' || Data[*i] == '/') {
			if (Stack[top - 1] && top != 0)
				for (int j = top - 1; Priority(Stack[j]) >= Priority(Data[*i]); j--)
					Blanket_Data_OUTPUT[count++] = Pop(Stack, &top);
			Push(Stack, &top, Data[*i]);
			Var_Number[*Var_count]--;
			Var[(*Var_count)++] = Var_Produce(Data, Var_count, Var_Number, Blanket);
			Var_Number[(*Var_count) - 1]++;
			Var_Number[*Var_count] = Var_Number[(*Var_count) - 1];                                 // ������ ����
		}
		else if (Data[*i] == '(') {
			if (Var_count == 0);
			else Var_Number[*Var_count - 1]++;                                                     // ( ����
			CBlanket(Data, Blanket_Data, i, Var, Var_count, Var_Number, Blanket);
			Var_Number[*Var_count]++;                                                              // ) ����
			for (int j = 0; Blanket_Data[j]; j++) Blanket_Data_OUTPUT[count++] = Blanket_Data[j];
		}
		else Blanket_Data_OUTPUT[count++] = Data[*i];
	}
	for (; top > 0;)
		Blanket_Data_OUTPUT[count++] = Pop(Stack, &top);
}

void Postfix_Notation() {
	char Stack[STACKSIZE] = { 0 };
	char Data[32] = { 0 };                                            // �����ڿ� �ǿ����ڸ� �޾��� ����
	char Data_OUTPUT[32] = { 0 };                                     // ��� �� ����� ����
	char Blanket_OUTPUT[16] = { 0 };
	int top = 0;
	int count = 0;
	system("cls");
	puts("����ǥ����� �Է����ּ���.");
	scanf_s("%s", Data, 32);                                          // �����ڿ� �ǿ����ڸ� �Է��Ѵ�.
	for (int i = 0; Data[i]; i++) {                                   // Data�� �� �̻� �����ִ°� ����������
		if (Data[i] == '+' || Data[i] == '-'                          // �������� Data�� �������̸�
			|| Data[i] == '*' || Data[i] == '/') {
			if (Stack[top - 1] && top != 0)                           // �鿡 �����ڰ� ������ ���� �켱������ ���Ѵ�.         
				for (int j = top - 1; Priority(Stack[j]) >= Priority(Data[i]); j--) Data_OUTPUT[count++] = Pop(Stack, &top);
			Push(Stack, &top, Data[i]);                               // ���� �鿡 �ִ� �������� �켱������ �����Ƿ��� ��������
		}				            				                  // �켱�������� ���ų� ������ �鿡 �ִ� �����ڰ� ����
		else if (Data[i] == '(') {                                    // ���������� �ȴ�.
			Blanket(Data, Blanket_OUTPUT, &i);                        // ��ȣ�� ������ ��ȣ���� ����ǥ�� �� ����Ѵ�.
			for (int j = 0; Blanket_OUTPUT[j]; j++) Data_OUTPUT[count++] = Blanket_OUTPUT[j];
		}
		else Data_OUTPUT[count++] = Data[i];
		printf("������... %s\n", Data_OUTPUT);
	}                                                                 // �ǿ����ڴ� �׳� �����Ѵ�.
	for (; top > 0;) {
		Data_OUTPUT[count++] = Pop(Stack, &top);                      // ���̿� ���ÿ� ���� �����ڸ� ���δ�.
		printf("������... %s\n", Data_OUTPUT);
	}
	puts("����ǥ����� ");
	printf("%s\n", Data_OUTPUT);
	system("pause");
	return;
}