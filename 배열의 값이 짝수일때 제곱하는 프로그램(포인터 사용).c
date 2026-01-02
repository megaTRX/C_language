#include <stdio.h>

void square(int* ptr);

int main(void) {
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 10; i++) {
		square(&arr[i]); // 함수 호출 : 배열 각 요소의 메모리 주소 연결
	}
	for (int i = 0; i < 10; i++) {
		printf("%d", arr[i]); // 변경된 배열의 각 요소 출력
		if (i + 1 < 10) { // 다음 요소가 남아 있는 경우에만 쉼표 출력
			printf(", ");
		}
	}

	return 0;
}

void square(int* ptr) {
	if (*ptr % 2 == 0) {
		*ptr = (*ptr) * (*ptr); // 메모리 주소 값의 제곱으로 변경
	}
}