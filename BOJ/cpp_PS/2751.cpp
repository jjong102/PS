#include <stdio.h>
#define OFFSET 1000000
#define MAX 2000001
int A[MAX] = {0};

int main(void) {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        A[temp + OFFSET] = 1;
    }

    for (int i = 0; i < MAX; i++) {
        while (A[i]--) {
            printf("%d\n", i - OFFSET);
        }
    }
    return 0;
}