#include <stdio.h>

int k,n,roznica;

int silnia(int num1){

    int i = num1;
    int wynik = 1;
    if (num1 == 0) return 1;

    while(i>0){

        wynik *= i;
        i--;
    }

    return wynik;
}

int main(){
    int valid;
    do {
        printf("Podaj wartość n: ");
        valid = scanf("%d",&n);
        if(valid == 0 || n < 0){
            printf("Podaj prawidłową wartość n, liczbę całkowitą dodatnią\n");
            fflush(stdin);
        }
    } while(valid == 0 || n < 0);

    do {
        printf("Podaj wartość k: ");
        valid = scanf("%d",&k);
        if(valid == 0 || k < 0){
            printf("Podaj prawidłową wartość k, liczbę całkowitą dodatnią\n");
            fflush(stdin);
        }
    } while(valid == 0 || k < 0);

    if (k > n) {
        printf("Wartość k nie może być większa od wartości n");
        return 1;
    }
    roznica = n-k;

    int ret1, ret2, ret3, wynik;
    ret1 = silnia(n);

    ret2 = silnia(k);
    ret3 = silnia(roznica);
    wynik = silnia(n)/(silnia(k)*silnia(roznica));
    printf("%d\n", roznica);
    printf("silnia n: %d silnia k: %d, silnia roznicy: %d, Newton: %d", ret1, ret2, ret3, wynik);
    return 0;
}