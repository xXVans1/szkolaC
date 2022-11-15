#include <stdio.h>


int main(){

    unsigned long long  int wynik,i;
    int n;
    wynik = 1;
    printf("Jaki liczbę: ");
    scanf("%lld", &n);
    if(n==0) {
        wynik = 1;
        printf("%ld! Wynosi %ld\n",n, wynik);
    }

    else{
    i = n;
    while(i>0){
        //wynik = wynik * i;
        wynik *= i;
        i--;

    }
       printf("%ld! Wynosi %ld\n",n, wynik);

    }
return 0;
}