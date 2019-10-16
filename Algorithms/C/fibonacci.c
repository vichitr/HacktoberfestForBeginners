#include <stdio.h>

int main() {
    int i, n, t = 0, t1 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (i = 1; i <= n; ++i) {
        printf("%d, ", t);
        nextTerm = t + t1;
        t = t1;
        t1 = nextTerm;
    }
    return 0;
}
