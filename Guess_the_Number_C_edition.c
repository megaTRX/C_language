#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(NULL));
	int num = rand() % 100 + 1;

	int answer = 0;
	int chance = 5;

	while(1) {
		printf("남은 기회 : %d\n", chance--);
		printf("숫자를 입력하세요.");
		scanf_s("%d", &answer); // 숫자 입력받기
		if (answer > num) {
			printf("DOWN ↓\n\n");
		}
		else if (answer < num) {
			printf("UP ↑\n\n");
		}
		else if (answer == num) {
			printf("정답입니다!\n\n");
			break;
		}
		else {
			printf("알 수 없는 오류가 발생했어요.\n\n");
		}
		if (chance == 0) {
			printf("모든 기회를 다 사용했습니다. 아쉽게도 실패했습니다.\n");
			printf("정답 : %d\n", num);
			break;
		}
	}
	return 0;
}