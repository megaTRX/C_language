#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	char * name; // 이름
	int age; // 나이
	char * character; // 특징
	int level; // 레벨
} CAT;

CAT cats[5]; // 큰 상자에 있는 고양이 목록을 배열로 선언
int collection[5] = { 0, 0, 0, 0, 0 }; // 고양이를 담는 작은 상자, 보유한 표시 (있으면 1, 없으면 0)

void initCats(); // 고양이 정보 초기화 함수 선언
void printCat(int selected); // 뽑은 고양의 정보 출력 함수 선언
int checkCollection(); // 모은 고양이 확인 함수 선언

int main(void) {
	srand(time(NULL)); // 난수 초기화
	initCats(); // 고양이 정보 초기화 함수 호출
	while (1) { // 작은 상자가 채워질 때까지 무한 반복
		printf("두근두근! 어느 고양이의 집사가 될까요?\nEnter를 눌러 확인하세요!"); // 안내 문구 출력
		getchar();
		int selected = rand() % 5;
		printCat(selected); // 뽑은 고양이 정보 출력 함수 호출
		collection[selected] = 1; // 뽑은 고양이를 작은 상자에 넣었다고 표시
		int collectAll = checkCollection(); // 모은 공양이 확인 함수 호출
		if (collectAll == 1) { // 고양이 5마리를 다 모으면 무한 반복문 탈출
			break;
		}
	}
	return 0;
}

void initCats() { // 고양이 정보 초기화 함수 정의
	cats[0].name = "깜냥이";
	cats[0].age = 5;
	cats[0].character = "온순함";
	cats[0].level = 1;
	cats[1].name = "귀요미";
	cats[1].age = 3;
	cats[1].character = "까칠함";
	cats[1].level = 2;
	cats[2].name = 7;
	cats[2].age = 2;
	cats[2].character = 2;
	cats[2].level = 2;
	cats[3].name = "까꿍이";
	cats[3].age = 2;
	cats[3].character = "시끄러움";
	cats[3].level = 4;
	cats[4].name = "돼냥이";
	cats[4].age = 1;
	cats[4].character = "늘 배고픔";
	cats[4].level = 5;
}

void printCat(int selected) { // 뽑은 고양이 정보 출력 함수 정의
	printf("\n\n=== 당신은 다음 고양이의 집사기 됐어요! ===\n\n");
	printf(" 이름 : %s\n", cats[selected].name);
	printf(" 나이 : %d\n", cats[selected].age);
	printf(" 특징 : %s\n", cats[selected].character);
	printf(" 레벨 : ");
	for (int i = 0; i < cats[selected].level; i++) {
		printf("%s", "★");
	}
	printf("\n\n");
}

int checkCollection() { // 모은 고양이 확인 함수 정의
	int collectAll = 1;
	printf("\n\n=== 보유한 고양이 목록이에요. ===\n\n"); // 안내 문구
	for (int i = 0; i < 5; i++) {
		if (collection[i] == 0) {
			printf("%10s", "(빈 상자)");
			collectAll = 0;
		}
		else {
			printf("%10s", cats[i].name);
		}
	}
	printf("\n===========================================\n\n");
	if (collectAll) {
		printf("\n\n축하합니다! 고양이 5마리를 모두 모았어요. 열심히 키워 주세요/\n\n");
	}
	return collectAll;
	
}