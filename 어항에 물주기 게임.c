#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int level;
int arrayFish[6];
int* cursor; // 어항 배열에 접근할 포인터 변수 선언
void initData();
void printfFishes();
void decreaseWater(long elapsedTime); // 어항의 물 증발시키는 함수 선언
int checkFishAlive(); // 모든 물고기가 죽었는지 확인하는 함수 선언

int main(void) {
	long startTime = 0;
	int num;
	long totalElapsedTime = 0; // 총 경과 시간
	long prevElapsedTime = 0; // 직전에 물을 준 시간 
	initData();
	startTime = clock(); // clock 함수는 프로그램 수행 시작 시점부터 흐른 시간을 밀리초 단위로 반환하는 함수
	cursor = arrayFish; // 포인터 변수에 어항 배열의 시작 주소 넣기
	while (1) {
		printfFishes();
		printf("몇 번 어항에 물을 줄까요?(1~6) "); // 입력 안내 문구
		scanf_s("%d", &num);
		if (num < 1 || num > 6) {
			printf("\n입력값이 잘못됐습니다.\n");
			continue;
			prevElapsedTime = totalElapsedTime - prevElapsedTime;
			printf("최근 경과 시간 : %ld초\n", prevElapsedTime);
		}
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;

		printf("총 경과 시간 : %ld초\n", totalElapsedTime);
		prevElapsedTime = totalElapsedTime - prevElapsedTime;

		printf("최근 경과 시간 : %ld초\n", prevElapsedTime);
		decreaseWater(prevElapsedTime);
		if (cursor[num - 1] <= 0) {
			printf("%d번 어항의 물고기는 이미 죽었으므로 물을 주지 않습니다.\n", num);
		}
		else if (cursor[num - 1] + 1 <= 100) {
			printf("%d번 어항에 물을 줍니다. \n\n", num);
			cursor[num - 1] += 1;
		}
		if (totalElapsedTime / 20 > level - 1) {
			level++;
			printf("*** 축하합니다. %d레벨에서 %d레벨로 올랐습니다. ***\n\n", level - 1, level);

			if (level == 5) {
				printf("\n\n축하합니다. 최고레벨을 달성했습니다. 게임을 종료합니다.\n\n");
				exit(0);
			}
		}
		if (checkFishAlive() == 0) {
			printf("모든 물고기가 죽었습니다. ㅠㅠ \n\n");
			exit(0);
		}
		else {
			printf("물고기가 아직 살아 있어요!\n\n");
		}
		prevElapsedTime = totalElapsedTime;
	}
	return 0;
}

void initData() {
	level = 1; // 레벨 초기화
	for (int i = 0; i < 6; i++) {
		arrayFish[i] = 100; // 어항 물 높이 초기화
	}
}

void printfFishes() {
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++) {
		printf("   %3d   ", arrayFish[i]); // 서식 지정자로 출력 결과 정렬
	}
	printf("\n\n"); // 가독성을 위해 추가
}

void decreaseWater(long elapsedTime) {
	for (int i = 0; i < 6; i++) {
		arrayFish[i] -= (level * 3 * (int)elapsedTime);
		if (arrayFish[i] < 0) {
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive() {
	for (int i = 0; i < 6; i++) {
		if (arrayFish[i] > 0) {
			return 1; // 참(true)
		}
	}
	return 0;
}
