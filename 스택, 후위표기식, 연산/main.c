#include "calculation.h"

void main() {
	int ki = Divide(2,4);
	while (1) {
		puts("1. 후위표기식");
		puts("2. 연산");
		puts("ESC. 끄기");
		ki = _getch();
		if (ki == 27) break;                // ESC
		if (ki == '1') Postfix_Notation();
		if (ki == '2') Calculation();
		system("cls");
	}
	return;
}