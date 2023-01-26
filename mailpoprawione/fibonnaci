#include <stdio.h>
#include <stdbool.h>

long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    long long pop = 0, akt = 1;
    for (int i = 2; i <= n; i++) {
        long long temp = akt;
        akt += pop;
        pop = temp;
    }

    return akt;
}

int main() {
    while (true) {
        int n;
        printf("\nPodaj n-ty wyraz ciągu Fibonacciego: ");
        while (scanf("%d", &n) != 1) {
            printf("Zła wartość n. Podaj poprawną wartość n: ");
            while (getchar() != '\n');
        }

        if (n < 0) {
            printf("Niepoprawny wyraz n");
        } else {
            printf("Wartość podanej n-tej ciągu Fibonacciego wynosi: %lld", fibonacci(n));
        }
    }

    return 0;
}
