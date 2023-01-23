#include <stdio.h>



int main() {
    float liczba1, liczba2, wynik;
    int wynik_scanf;
    do {
        printf("Podaj pierwszą liczbę: ");
        wynik_scanf = scanf("%f", &liczba1);
        if (wynik_scanf != 1) {
            printf("Nieprawidłowy format liczby. Spróbuj ponownie\n");
            while (getchar() != '\n');
        }
    } while (wynik_scanf != 1);

    do {
        printf("Podaj drugą liczbę: ");
        wynik_scanf = scanf("%f", &liczba2);
        if (wynik_scanf != 1) {
            printf("Nieprawidłowy format liczby. Spróbuj ponownie\n");
            while (getchar() != '\n');
        }
    } while (wynik_scanf != 1);

    wynik = liczba1 + liczba2;
    printf("Wynik dodawania: %f\n", wynik);

    return 0;
}
