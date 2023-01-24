#include <stdio.h>

int main() {
    int liczba, system, i;
    int tab[75];

    while (1) {
        printf("Podaj liczbe w systemie dziesietnym: ");

        if (!scanf("%d", &liczba)) {
            printf("Podaj poprawna liczbe!\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Podaj system od 2 do 16: ");

        if (!scanf("%d", &system)) {
            printf("Podaj poprawną liczbę!\n");
            while (getchar() != '\n');
            continue;
        }

        i = 0;
        while (liczba > 0) {
            tab[i] = liczba % system;
            liczba /= system;
            i++;
        }

        printf("Liczba w systemie %d-kowym: ", system);
        for (i--; i >= 0; i--) {
            if (tab[i] > 9)
                printf("%c", tab[i] + 55); //znaki ASCII
            else
                printf("%d", tab[i]);
        }
        printf("\n");
    }

    return 0;
}