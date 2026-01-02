#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arrayAnimal[4][5];
char* strAnimal[10];
int checkAnimal[4][5];

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestion();
int foundAllAnimals();

int main(void) {
    srand(time(NULL)); // [추가] 실행할 때마다 결과가 달라지도록 난수 초기화

    initAnimalArray();
    initAnimalName();  // [중요] 이 함수를 호출해야 null이 안 나옵니다.
    shuffleAnimal();

    int failCount = 0;

    while (1) {
        int select1 = 0;
        int select2 = 0;

        printAnimals(); // 정답 보기
        printQuestion(); // 현재 진행 상황 보기

        printf("\n뒤집을 카드 2장을 고르세요. (예: 12 4) -> ");
        scanf_s("%d %d", &select1, &select2);

        if (select1 == select2) continue;

        int firstSelect_x = conv_pos_x(select1);
        int firstSelect_y = conv_pos_y(select1);
        int secondSelect_x = conv_pos_x(select2);
        int secondSelect_y = conv_pos_y(select2);

        // 이미 뒤집힌 카드가 아니고, 두 카드의 동물이 같은 경우
        if ((checkAnimal[firstSelect_x][firstSelect_y] == 0
            && checkAnimal[secondSelect_x][secondSelect_y] == 0)
            && (arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y])) {

            printf("\n\n빙고! %s 발견\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            checkAnimal[firstSelect_x][firstSelect_y] = 1;
            checkAnimal[secondSelect_x][secondSelect_y] = 1; // [수정] 두 번째 카드도 체크
        }
        else {
            printf("\n\n땡! 틀렸거나 이미 뒤집힌 카드입니다.\n");
            printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]); // [수정] secondSelect_x 사용
            printf("\n");
            failCount++;
        }

        if (foundAllAnimals() == 1) {
            printf("\n\n축하합니다! 모든 동물을 찾았습니다.\n");
            printf("총 %d번 실패했습니다.\n", failCount);
            break;
        }
    }
    return 0;
}

// --- 이하 함수 구현부 ---

void initAnimalArray() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            arrayAnimal[i][j] = -1;
            checkAnimal[i][j] = 0; // check 배열도 초기화
        }
    }
}

void initAnimalName() {
    strAnimal[0] = "원숭이";
    strAnimal[1] = "하마";
    strAnimal[2] = "강아지";
    strAnimal[3] = "고양이";
    strAnimal[4] = "돼지";
    strAnimal[5] = "코끼리";
    strAnimal[6] = "기린";
    strAnimal[7] = "낙타";
    strAnimal[8] = "타조";
    strAnimal[9] = "호랑이";
}

void shuffleAnimal() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 2; j++) {
            int pos = getEmptyPosition();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);
            arrayAnimal[x][y] = i;
        }
    }
}

int getEmptyPosition() {
    while (1) {
        int randPos = rand() % 20;
        int x = conv_pos_x(randPos);
        int y = conv_pos_y(randPos);
        if (arrayAnimal[x][y] == -1) {
            return randPos;
        }
    }
}

int conv_pos_x(int x) { return x / 5; }
int conv_pos_y(int y) { return y % 5; }

void printAnimals() {
    printf("\n======== 동물 위치 (정답) =======\n\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%10s", strAnimal[arrayAnimal[i][j]]);
        }
        printf("\n");
    }
    printf("\n============================\n");
}

void printQuestion() {
    printf("\n(문제판)\n\n");
    int seq = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (checkAnimal[i][j] != 0) {
                printf("%10s", strAnimal[arrayAnimal[i][j]]);
            }
            else {
                printf("%10d", seq);
            }
            seq++;
        }
        printf("\n");
    }
}

int foundAllAnimals() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (checkAnimal[i][j] == 0) return 0;
        }
    }
    return 1;
}