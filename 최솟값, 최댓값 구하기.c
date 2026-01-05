// 세 정수 값을 입력하고 최댓값을 구합니다.
#include <stdio.h>

// 세 값의 최댓값을 구하는 함수
int max3(int a, int b, int c)
{
	int max = a; // max에 a의 값을 대입
	if (b > max) { // b가 max보다 크면
		max = b; // max에 b의 값을 대입
	}
	if (c > max) { // c가 max보다 크면
		max = c; // max에 c의 값을 대입
	}

	return max; // 구한 최댓값을 호출한 곳으로 반환
}

// 네 값의 최댓값을 구하는 함수
int max4(int a, int b, int c, int d)
{
	int max = a; // max에 a의 값을 대입
	if (b > max) { // b가 max보다 크면
		max = b; // max에 b의 값을 대입
	}
	if (c > max) { // c가 max보다 크면
		max = c; // max에 c의 값을 대입
	}
	if (d > max) {
		max = d;
	}
	return max; // 구한 최댓값을 호출한 곳으로 반환
}

// 세 값의 최솟값을 구하는 함수
int min3(int a, int b, int c)
{
	int min = a;
	if (b < min) {
		min = b;
	}
	if (c < min) {
		min = c;
	}
	return min;
}

int min4(int a, int b, int c, int d) {
	int min = a;
	if (b < min) {
		min = b;
	}
	if (c < min) {
		min = c;
	}
	if (d < min) {
		min = d;
	}
	return min;
}

int main(void) {
	printf("max3(%d %d %d) = %d\n", 3, 2, 1, max3(3, 2, 1));
	printf("max4(%d %d %d %d) = %d\n", 3, 2, 1, 4, max4(3, 2, 1, 4));
	printf("min3(%d %d %d) = %d\n", 3, 2, 1, min3(3, 2, 1));
	printf("min4(%d %d %d %d) = %d\n", 3, 2, 1, 4, min4(3, 2, 1, 4));

	return 0;
}