#include <stdio.h>

void swap(int a, int b);
void swap_addr(int* a, int* b);

int main(void) {
	int a = 10;
	int b = 20;
	printf("a의 주소 : %p\n", &a);
	printf("b의 주소 : %p\n", &b);
	printf("swap() 함수 호출 전 => a : %d, b : %d\n", a, b); // 교환하기 전 변수 값 출력
	swap(a, b);
	printf("swap() 함수 호출 후 => a : %d, b : %d\n", a, b); // 교환한 후 변수 값 출력
	printf("swap_addr() 함수 호출 전 => a : %d, b : %d\n", a, b);
	swap_addr(&a, &b); // 함수 호출, 주소 전달
	printf("swap_addr() 함수 호출 후 => a : %d, b : %d\n", a, b);
	return 0;
}

void swap(int a, int b) {
	printf("swap() 함수 안에서 a의 주소 : %p\n", &a);
	printf("swap() 함수 안에서의 b의 주소 : %p\n", &b);
	int temp = a;
	a = b;
	b = temp;
	printf("swap() 함수 안 => a : %d, b : %d\n", a, b);
}

void swap_addr(int* a, int* b) { // 함수 정의
	int temp = *a; // 변수 temp를 선언하고 포인터 변수 a에 담긴 주소의 실제 값 저장
	*a = *b; // 포인터 변수 b에 담긴 주소의 실제 값을 포인터 a에 담긴 주소의 값으로 저장
	*b = temp; // 변수 temp의 값을 포인터 변수 b에 담긴 주소의 실제 값으로 저장
	printf("swap_addr() 함수 안 => a : %d, b : %d\n", *a, *b); // a와 b에 담긴 주소의 실제 값 출력
}