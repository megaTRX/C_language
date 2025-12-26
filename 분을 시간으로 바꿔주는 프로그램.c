#include <stdio.h>
#include <stdlib.h>

void cover_time(int time);

int main(void) {
	int time;
	printf("분 단위의 시간을 입력하시면 ?시간과 ?분으로 변환해드립니다.\n");
	scanf_s("%d", &time);
	cover_time(time);


	return 0;
}

void cover_time(int time) {
	int hour = time / 60;
	int minute = time % 60;
	printf("%d시간 %d분\n", hour, minute);
}