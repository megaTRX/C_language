#include <stdio.h>

void triangleLB(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void triangleLU(int n) {
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void triangleRU(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j < i) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
}

void triangleRB(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j < n - i + 1) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
}

int main() {
	//triangleLB(5);
	// triangleLU(5);
	// triangleRU(5);
	// triangleRB(5);

	
	return 0;
}