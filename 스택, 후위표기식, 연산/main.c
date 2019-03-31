#include "calculation.h"

void main() {
	int ki = 0;
	while (1) {
		puts("1. 후위표기식");
		puts("2. 연산");
		puts("ESC. 끄기");
		ki = _getch();
		if (ki == 27) break;                // ESC
		if (ki == '1') Postfix_Notation();
		system("cls");
	}
	return;
}