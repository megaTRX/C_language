// 2자리의 양수(10~99)를 입력하는 프로그램
#include <stdio.h>

int main() {
    int i, j, k;
	printf("정사각형을 출력합니다.\n");
	printf("입력할 수 : ");
	scanf_s("%d", &k);
    
	for (i = 1; i <= k; i++) {
		for (j = 1; j <= k; j++) {
			printf("*");
		}
		printf("\n");
	}
    return 0;
}