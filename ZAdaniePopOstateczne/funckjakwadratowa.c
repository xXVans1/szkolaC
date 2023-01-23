#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    int valid;

    printf("Funkcja kwadratowa: y = ax^2 +bx +c \n");

    do {
        printf("Podaj wspolczynnik a: ");
        valid = scanf("%lf", &a);
        if (valid != 1) {
            printf("Niepoprawy input! Sprobuj ponownie.\n");
            scanf("%*s");
        }
    } while (!valid);

    do {
        printf("Podaj wspolczynnik b: ");
        valid = scanf("%lf", &b);
        if (valid != 1) {
            printf("Niepoprawny input! Sprobuj ponownie.\n");
            scanf("%*s");
        }
    } while (!valid);

    do {
        printf("Podaj wspolczynnik c: ");
        valid = scanf("%lf", &c);
        if (valid != 1) {
            printf("Niepoprawny input! Sprobuj ponownie.\n");
            scanf("%*s");
        }
    } while (!valid);

    double delta = b * b - 4 * a * c;

    if (delta < 0) {
        printf("Funkcja nie ma rzeczywistych miejsc zerowych.\n");
    } else if (delta == 0) {
        double x = -b / (2 * a);
        printf("Funkcja ma jedno miejsce zerowe: %lf\n", x);
    } else {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        if(x1<0 && x2<0){
            printf("x1 oraz x2 sa ujemne.");
        }
        else if(x1<0){
            printf("x1 jest ujemny.\nx2 wynosi: %lf", x2);
        }
        else if(x2<0){
            printf("x2 jest ujemny.\nx1 wynosi: %lf", x1);
        }
        else {
            printf("Funkcja ma dwa meijsca zerowe: %lf oraz %lf\n", x1, x2);
        }
    }

    return 0;
}