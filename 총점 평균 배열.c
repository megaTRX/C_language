#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(NULL));
	int score[5] = { 76, 84, 80, 92, 96 };
	int sum = 0;
	float average = 0.0f; // Æò±Õ
	for (int i = 0; i < 5; i++) {
		sum += score[i];
	}
	average = sum / 5.0f; // Æò±Õ °è»ê
	printf("ÃÑÁ¡Àº %dÁ¡ Æò±ÕÀº %.1fÁ¡ÀÔ´Ï´Ù.\n", sum, average);
	return 0;
}