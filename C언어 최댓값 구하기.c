// 세 정수 값을 입력하고 최댓값을 구합니다.
#include <stdio.h>

int main(void) {
	int a, b, c; // 세 정수 값을 저장할 변수 선언
	int max;
	printf("세 정수의 최댓값을 구합니다.\n ");
	printf("a의 값: "); scanf_s("%d", &a);
	printf("b의 값: "); scanf_s("%d", &b);
	printf("c의 값: "); scanf_s("%d", &c);
	max = a; // max에 a의 값을 대입
	if (b > max) { // b가 max보다 크면
		max = b; // max에 b의 값을 대입
	}
	if (c > max) { // c가 max보다 크면
		max = c; // max에 c의 값을 대입
	}

	printf("최댓값은 %d입니다.\n", max);

	return 0;
 }