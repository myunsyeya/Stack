#include "stack.h"

void Push(char Stack[], int *top, char data) {       // 스택에 연산자가 차곡 차곡 쌓이는 과정
	if (*top == STACKSIZE) {                         // 연산자가 10개 들어갔으면,
		puts("더 이상 연산자를 출력할 수 없습니다.");
		return;
	}
	Stack[(*top)++] = data;
}

char Pop(char Stack[], int *top) {                    // 탑에서 연산자를 하나씩 빼오는 과정
	if (*top == 0) return ERROR_VALUE;                // 연산자가 더 이상 없다면(탑이 비었다면)
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

void Postfix_Notation() {
	char Stack[STACKSIZE] = { 0 };
	char Data[32] = { 0 };                                            // 연산자와 피연산자를 받아줄 공간
	char Data_OUTPUT[32] = { 0 };                                     // 출력 시 사용할 공간
	char Blanket_OUTPUT[16] = { 0 };
	int top = 0;
	int count = 0;
	system("cls");
	puts("중위표기식을 입력해주세요.");
	scanf_s("%s", Data, 32);                                          // 연산자와 피연산자를 입력한다.
	for (int i = 0; Data[i]; i++) {                                   // Data에 더 이상 남아있는게 없을때까지
		if (Data[i] == '+' || Data[i] == '-'                          // 받으려는 Data가 연산자이면
			|| Data[i] == '*' || Data[i] == '/') {
			if (Stack[top - 1] && top != 0)                           // 톱에 연산자가 있으면 둘의 우선순위를 비교한다.         
				for (int j = top - 1; Priority(Stack[j]) >= Priority(Data[i]); j--) Data_OUTPUT[count++] = Pop(Stack, &top);
			Push(Stack, &top, Data[i]);                               // 만일 톱에 있는 연산자의 우선순위가 보관되려는 연산자의
		}				            				                  // 우선순위보다 높거나 같으면 톱에 있는 연산자가 먼저
		else if (Data[i] == '(') {                                    // 빠져나오게 된다.
			Blanket(Data, Blanket_OUTPUT, &i);                        // 괄호를 만나면 괄호안을 후위표기 후 계산한다.
			for (int j = 0; Blanket_OUTPUT[j]; j++) Data_OUTPUT[count++] = Blanket_OUTPUT[j];
		}
		else Data_OUTPUT[count++] = Data[i];
		printf("연산중... %s\n", Data_OUTPUT);
	}                                                                 // 피연산자는 그냥 저장한다.
	for (; top > 0;) {
		Data_OUTPUT[count++] = Pop(Stack, &top);                      // 말미에 스택에 남은 연산자를 붙인다.
		printf("연산중... %s\n", Data_OUTPUT);
	}
	puts("후위표기식은 ");
	printf("%s\n", Data_OUTPUT);
	system("pause");
	return;
}