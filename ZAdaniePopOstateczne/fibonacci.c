#include <stdio.h>
#include <stdbool.h>



int fibonnaci(int liczba){
    if(liczba<=1){
        return liczba;
    }
    else{
        return fibonnaci(liczba - 1) + fibonnaci(liczba -2);
    }

}

int main(){

    while(true) {
    int wyraz;
    printf("\nPodaj n-ty wyraz ciągu Fibonacciego: ");
    while (scanf("%d", &wyraz) != 1) {
        printf("Zła wartość n. Podaj poprawną wartość n: ");
        while (getchar() != '\n');
    }
    if(wyraz < -1){
        printf("NIepoprawny wyraz n");
    }
    else if(wyraz == 0){
        printf("Wartość podanej n-tej cągu fibonacciego wynosi: 0");
    }

    else{
        printf("Wartość pdoanej n=tej ciągu fibonacciego wynosi: %d", fibonnaci(wyraz));
    }


}
    return 0;
}