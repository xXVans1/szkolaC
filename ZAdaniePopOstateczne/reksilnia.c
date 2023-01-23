#include <stdio.h>

int silnia(int n){
    if(n == 0)
        return 1;
    else
        return n * silnia(n-1);
}

int main(){
    long int n;
    long int valid;
    do {
        printf("Podaj wartość n: ");
        valid = scanf("%ld",&n);
        if(valid != 1 || n < 0){
            printf("Podaj prawidłową (wartość n, liczbę całkowitą dodatnią)\n");
            fflush(stdin);
        }
        else if(n == 0){
            printf("Silnia z 0 wynosi 1");
        }
    } while(valid != 1 || n < 0);
    int result = silnia(n);
    printf("Silnia z %ld jest równa %ld", n, result);
    return 0;
}