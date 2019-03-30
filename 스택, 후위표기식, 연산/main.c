#include "stack.h"
#include "calculation.h"

void main() {
	char Stack[STACKSIZE] = { 0 };
	char Data[32] = { 0 };                                            // �����ڿ� �ǿ����ڸ� �޾��� ����
	char Data_OUTPUT[32] = { 0 };                                     // ��� �� ����� ����
	char Blanket_OUTPUT[16] = { 0 };
	int top = 0;
	int count = 0;
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
	}                                                                 // �ǿ����ڴ� �׳� �����Ѵ�.
	for (; top > 0;)
		Data_OUTPUT[count++] = Pop(Stack, &top);                      // ���̿� ���ÿ� ���� �����ڸ� ���δ�.
	puts("����ǥ����� ");
	printf("%s\n", Data_OUTPUT);
	system("pause");
	return;
}