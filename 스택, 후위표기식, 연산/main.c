#include "calculation.h"

void main() {
	int ki = 0;
	while (1) {
		puts("1. ����ǥ���");
		puts("2. ����");
		puts("ESC. ����");
		ki = _getch();
		if (ki == 27) break;                // ESC
		if (ki == '1') Postfix_Notation();
		system("cls");
	}
	return;
}