#include <stdio.h>

int sumof(int a, int b) {
    int sum = 0;

    // a가 b보다 작거나 같을 때
    if (a <= b) {
        for (int i = a; i <= b; i++) {
            sum += i;
        }
    }
    // b가 a보다 작을 때 (즉, a > b인 경우)
    else {
        for (int i = b; i <= a; i++) {
            sum += i;
        }
    }
    return sum;
}

int main(void) {
    // 6부터 4까지의 합 (4+5+6 = 15)
    printf("%d부터 %d까지의 합은 %d입니다.\n", 6, 4, sumof(6, 4));
    return 0;
}