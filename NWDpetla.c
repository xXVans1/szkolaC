#include <stdio.h>


int main(){

    int m,n,r;
    
    printf("Podaj 1 numer: ");
    scanf("%d",&m);
    printf("Podaj 2 numer: ");
    scanf("%d",&n);
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