#include <stdio.h>

int main() {
    int n;
    int count = 0; // 자릿수를 저장할 변수

    printf("양의 정수를 입력하세요: ");
    scanf_s("%d", &n); // 정수 입력받기

    // do-while 문 시작
    do {
        n = n / 10; // 숫자를 10으로 나누어 마지막 자릿수를 제거
        count++;    // 카운트 1 증가
    } while (n > 0); // n이 0보다 클 때까지 반복

    printf("그 수는 %d자리입니다.\n", count);

    return 0;
}