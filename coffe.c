#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {;

	int coffeAmount = 0;
	int sandwichAmount = 0;
	int totalPrice = 0;

	printf("커피의 수량을 입력하세요: ");
	scanf_s("%d", &coffeAmount);

	printf("샌드위치의 수량을 입력하세요: ");
	scanf_s("%d", &sandwichAmount);

	if (sandwichAmount > 0 && coffeAmount) {
		totalPrice = (sandwichAmount * 6000) + (coffeAmount * 3500);
	}
	else {
		totalPrice = (sandwichAmount * 6000) + (coffeAmount * 4500);
	}
	

	printf("주문하신 메뉴의 총 금액은 %d원 입니다.", totalPrice);
	return 0;
}