#include <stdio.h>
#include <math.h>

double calkowanie(double (*f)(double), double a, double b, int n) {
    if (n <= 0) {
        printf("N powinno byc wieksze od 0\n");
        return NAN;// zwraca not a number
    }
    if (a >= b) {
        printf("A powinno być mniejsze od b!\n");
        return NAN;// zwraca not a number
    }
    double h = (b - a) / n;
    double wynik = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++) {
        wynik += f(a + i * h);
    }
    wynik *= h;
    return wynik;
}

double f(double x) {
    return 2*x * x; //funkcja
}

int main() {
    double a = 0;
    double b = 2;
    int n = 1000;
    double wynik = calkowanie(f, a, b, n);
    if (isnan(wynik)) return 1;  // isnan = is not a number , kiedy nie jest liczba, zwraca 1
    printf("Wynik całkowania: %.7lf", wynik);
    return 0;
}
