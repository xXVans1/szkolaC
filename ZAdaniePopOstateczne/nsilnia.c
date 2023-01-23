#include <stdio.h>

#define MAXIMUM 500
void silnia(int n);
int mnozenie(int res[],int rozmiar_tablicy, int x);


int main() {
    int n;
    printf("\nPodaj liczbę do obliczenia silni: ");
    while (scanf("%d", &n) != 1) {
        printf("Niepoprawna liczba, spróbuj ponownie: ");
        while (getchar() != '\n');
    }

    printf("Silnia %d wynosi: ",n);
    silnia(n);

    return 0;
}

int mnozenie(int res[],int rozmiar_tablicy, int x){
    int przeniesienie = 0;

    for(int i=0;i<rozmiar_tablicy;i++)
    {
        int prod = res[i] *x+przeniesienie;
        res[i] = prod%10;
        przeniesienie = prod/10;
    }


    while(przeniesienie)
    {
        res[rozmiar_tablicy] = przeniesienie%10;
        przeniesienie = przeniesienie/10;
        rozmiar_tablicy++;
    }
    return rozmiar_tablicy;
}

void silnia(int n){
    int res[MAXIMUM];
    res[0]=1;
    int rozmiar_tablicy=1;

    for(int x =2;x<=n;x++){
        rozmiar_tablicy = mnozenie(res, rozmiar_tablicy, x);
    }

    for(int i=rozmiar_tablicy-1;i>=0;i--){
        printf("%d", res[i]);
    }
}



