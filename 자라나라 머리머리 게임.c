#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(NULL));
	int treatment = rand() % 4;
	printf("\n\n === 자라나라 머리카락 게임 === \n\n");
	int cntShowBottle = 0;
	int prevCntShowBottle = 0;
	for (int i = 1; i <= 3; i++) {
		int bottle[4] = { 0, 0, 0, 0 };
			do {
				cntShowBottle = rand() % 2 + 2;
			} while (cntShowBottle == prevCntShowBottle);
		prevCntShowBottle = cntShowBottle;
		printf("> %d번째 테스트 : ", i);
		int isIncluded = 0;
		for (int j = 0; j < cntShowBottle; j++) {
			int randBottle = rand() % 4;
			if (bottle[randBottle] == 0) {
				bottle[randBottle] = 1; // 값을 0 >> 1
				if (randBottle == treatment) {
					isIncluded = 1;
				}
			}
			else {
				j--; // 반복 횟수 조정
			}
		}

		for (int k = 0; k < 4; k++) {
			if (bottle[k] == 1) {
				printf("%d", k + 1);
			}
		}
		printf("번 물약을 머리에 바릅니다.\n\n");
		if (isIncluded == 1) { // 약병 조합에 발모제가 포함된 경우
			printf(">> 성공! 머리카락이 났어요!!\n");
		}
		else { // 약병 조합에 발모제가 포함되지 않은 경우
			printf(">> 실패! 머리카락이 나지 않았어요. ㅠㅠ\n\n");
		}
		printf("\n  계속하려면 Enter를 누르세요.  \n");
		getchar();
	}
	// 사용자 입력받기
	printf("\n\n발모제는 몇 번일까요? ");
	int answer;
	scanf_s("%d", &answer);
	if (answer == treatment + 1) {
		printf("\n>> 정답입니다!\n");
	}
	else {
		printf("\n>> 땡 ! 틀렸어요. 정답은 %d번입니다.\n", treatment + 1);
	}
	return 0;
}