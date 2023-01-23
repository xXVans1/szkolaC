#include <stdio.h>


int main(){

    int m,n,r;

    printf("Podaj 1 numer: ");
    while (scanf("%d", &m) != 1 || m <= 0 || m != (int)m) { // sprawdzamy, czy użytkownik podał poprawną liczbę
        printf("Zła liczba, spróbuj ponownie: ");
        while (getchar() != '\n');}
        printf("Podaj 2 numer: ");
        while (scanf("%d", &n) != 1 || n <= 0 || n != (int)n) { // sprawdzamy, czy użytkownik podał poprawną liczbę
            printf("Zła liczba, spróbuj ponownie: ");
            while (getchar() != '\n');
        }
        if(n == 0)
            printf("NWD to: %d",m);
        else{
            while(n>0){
                r = m%n;
                m = n;
                n =r;
            }
            printf("NWD = %d \n",m);
        }




        return 0;
    }
