#include <stdio.h>
#include <math.h>
int prosta_petla();

int main() {
    printf("\nOperatory matematyczne: \nDodawanie: +\nOdejmowanie: -\nMnozenie: *\nDzielenie: /\nPotegowanie: ^\nPierwiastkowanie: |\nSinus: s\nCosinus: c\nTangens: t\nWyjscie - q");
    while(1){
        if(prosta_petla() != 0){
            return 0;
        }
    }
}
int prosta_petla(){

    double liczba1, liczba2, result;
    char operacja;
    printf("\nPodaj operator: ");
    scanf("%s", &operacja);

    if(operacja == '+')
    {
        double wynik;
        printf("Wprowadz pierwsza liczbe: ");
        scanf("%lf", &liczba1);
        printf("Wprowadz druga liczbe: ");
        scanf("%lf", &liczba2);
        wynik = liczba1 + liczba2;
        printf("Wynik: %.3lf", wynik);
    }
    else if(operacja=='-')
    {
        double wynik;
        printf("Podaj pierwsza liczbe: ");
        scanf("%lf", &liczba1);
        printf("Wprowadz druga liczbe: ");
        scanf("%lf", &liczba2);
        wynik = liczba1 - liczba2;
        printf("Wynik: %.3lf", wynik);
    }
    else if(operacja=='*')
    {
        double wynik;
        printf("Podaj pierwsza liczbe: ");
        scanf("%lf", &liczba1);
        printf("Podaj druga liczbe: ");
        scanf("%lf", &liczba2);
        wynik = liczba1 * liczba2;
        printf("Wynik: %.5lf", wynik);
    }
    else if(operacja=='/')
    {
        printf("Podaj pierwsza liczbe: ");
        scanf("%lf", &liczba1);
        printf("Podaj druga liczbe: ");
        scanf("%lf", &liczba2);
        double result = liczba1 / liczba2;
        printf("Wynik: %.5lf", result);
    }

    else if(operacja == '|')
    {
        printf("Wprowadz liczbe, ktora chcesz spierwiastkowac: ");
        scanf("%lf", &liczba1);
        double result = sqrt(liczba1);
        printf("Wynik: %.3lf\n", result);
        printf("Wpisz q by zakonczyc dzialanie kalkulatora");
    }
    else if(operacja == '^')
    {
        printf("Wprowadz podstawe potegi: ");
        scanf("%lf", &liczba1);
        printf("Wprowadz numer potegi: ");
        scanf("%lf", &liczba2);
        double result = pow(liczba1, liczba2);
        printf("Wynik: %.3lf", result);
    }


    else if(operacja == 's'){
        printf("Podaj wartosc Sinusa:" );
        scanf("%lf", &liczba1);
        double result = sin(liczba1);
        printf("Wartosc sin dla x: %.5lf", result);
    }
    else if(operacja == 'c'){
        printf("Podaj wartosc Cosinusa:" );
        scanf("%lf", &liczba1);
        double result = cos(liczba1);
        printf("Wartosc Cosinusa wynosi: %.5lf", result);
    }
    else if(operacja == 't'){
        printf("Podaj wartosc Tangensa:" );
        scanf("%lf", &liczba1);
        double result = tan(liczba1);
        printf("Wartosc Tangensa wynosi: %.5lf", result);
    }
    else if (operacja == 'q') {
        return -1;
    }
    else {
        printf("Nieprawidlowa operacja\n");
    }
    return 0;
}