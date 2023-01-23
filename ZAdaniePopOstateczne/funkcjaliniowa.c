#include <stdio.h>

int main(){

    float a, b, x;
    int wynik_scanf;

    do {
        printf("Wzór na miejsce zerowe: x=-b/a\nPodaj wartość b: ");
        wynik_scanf = scanf("%f", &b);
        if (wynik_scanf != 1) {
            printf("Nieprawidłowy format liczby. Spróbuj ponownie\n");
            while (getchar() != '\n');
        }
    } while (wynik_scanf != 1);

    do {
        printf("Podaj wartość a: ");
        wynik_scanf = scanf("%f", &a);
        if (wynik_scanf != 1) {
            printf("Nieprawidłowy format liczby. Spróbuj ponownie\n");
            while (getchar() != '\n');
        }
    } while (wynik_scanf != 1);

    if(a==0){
        printf("Niedozwolona operacja, \"a\" nie może być równe zero\n");
        return 1;
    }
    x = -b / a;

    printf("Miejsce zerowe to: %f\n", x);


    return 0;
}