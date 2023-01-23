#include <stdio.h>
#include <math.h>

double srednia_arytmetyczna(const double* buffer, int rozmiar) {
    double suma = 0;
    for (int i=0; i<rozmiar; i++) {
        suma += buffer[i];
    }
    return suma / rozmiar;
}

double odchylenie_standardowe(const double* buffer, int rozmiar) {
    double m = srednia_arytmetyczna(buffer, rozmiar);
    double suma = 0;
    for (int i=0; i<rozmiar; i++) {
        suma += pow(buffer[i] - m, 2);
    }
    return sqrt(suma / rozmiar);

}

int main()
{
    int BUFFER_N_MAX= 1000;
    double buffer[BUFFER_N_MAX];
    double x;
    int index = 0;

    while (scanf("%lf", &x) != EOF) {
        printf("Odczytano z pliku: %f\n", x);
        buffer[index++] = x;
    }

    printf("Srednia arytmetyczna: %lf\n", srednia_arytmetyczna(buffer, index));
    printf("Ochylenie standardowe: %lf", odchylenie_standardowe(buffer, index));
    return 0;
}