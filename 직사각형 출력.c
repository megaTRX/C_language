#include <stdio.h>

int main() {
	int i, j, k, n;
	printf("직사각형을 출력합니다.\n");
	printf("높이 : ");
	scanf_s("%d", &k);
	printf("너비 : ");
	scanf_s("%d", &n);

	for (i = 1; i <= k; i++) {
		for (j = 1; j <= n; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}