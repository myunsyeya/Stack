#include "stack.h"
#include "calculation.h"

void main() {
	char Stack[STACKSIZE] = { 0 };
	char Data[32] = { 0 };                                            // 연산자와 피연산자를 받아줄 공간
	char Data_OUTPUT[32] = { 0 };                                     // 출력 시 사용할 공간
	char Blanket_OUTPUT[16] = { 0 };
	int top = 0;
	int count = 0;
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
	}                                                                 // 피연산자는 그냥 저장한다.
	for (; top > 0;)
		Data_OUTPUT[count++] = Pop(Stack, &top);                      // 말미에 스택에 남은 연산자를 붙인다.
	puts("후위표기식은 ");
	printf("%s\n", Data_OUTPUT);
	system("pause");
	return;
}