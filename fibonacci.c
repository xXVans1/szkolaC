#include <stdio.h>

int main(){

    int wyraz, wynik, a = 1, b = 0;
    printf("Podaj n-ty wyraz ciągu Fibonacciego: ");
    scanf("%d",&wyraz);
    for(int i = 0; wyraz>i; i++){

        wynik = b;
        b = b+a;
        a=b-a;
    }

    printf("%d ciągu Fibonacciego wynosi: %d",wyraz,wynik);

    return 0;
}