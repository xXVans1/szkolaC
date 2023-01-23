#include <stdio.h>
#include <string.h>
#include <ctype.h>


int indexOf(char c){
    char znaki[] = "IVXLCDM";

    int i;
    for(i = 0; i< 7;i++){
        if(znaki[i] == c){
            return i;
        }
    }
    return -1;
}


void RzymskaNaDziesietna(char *rzymska){

    int dziesietne[] = {1, 5, 10, 50, 100, 500, 1000};


    int n = 0, i, j;
    int len = strlen(rzymska);
    int valid = 1;
    for (i = 0; i < len; i++) {
        if (!isalpha(rzymska[i]) || !isupper(rzymska[i]) || indexOf(rzymska[i]) == -1) {
            valid = 0;
            break;
        }
    }
    if (!valid) {
        printf("Podaj prawidlowa liczbe rzymska (Dostępne znaki: I, V, X, L, C, D, M)\n");
        return;
    }
    i = strlen(rzymska) - 1;
    n = n + dziesietne[indexOf(rzymska[i])];
    j = i;
    i--;

    while(i >= 0){
        if(indexOf(rzymska[i]) >= indexOf(rzymska[j])){
            n = n + dziesietne[indexOf(rzymska[i])];
        }
        else{
            n = n - dziesietne[indexOf(rzymska[i])];
        }
        i--;
        j--;
    }
    printf("Liczba = %d\n", n);
}

void DziesietneNaRzymskie(int num)
{
    int dziesietne[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char *znaki[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    int i = 0;
    if (num <= 3999){
        while(num){
            while(num/dziesietne[i]){
                printf("%s",znaki[i]);
                num = num - dziesietne[i];
                }
            i++;
            }
    }
    else{
        printf("Podaj liczbę z zakresu 1-3999");
    }

}
int main(){
    char rzymska[70];
    char exit_choice;
    int num;
    int user_choice;
    do {
        start:
        printf("Z dziesietnego na rzymski - 1\nZ Rzysmkiego na dziesietny - 2: ");
        scanf("%d", &user_choice);
        if (user_choice == 1) {

            printf("Podaj numer: ");
            scanf("%d", &num);
            DziesietneNaRzymskie(num);
            printf("\n");

        }
        if (user_choice == 2) {
            printf("Podaj liczbe rzymską: ");
            scanf("%s", &rzymska);
            RzymskaNaDziesietna(rzymska);
        }
        if (user_choice > 2) {
            printf("\nZły wybór!\n");
            goto start;
        }

    }while(toupper(exit_choice) != 'N');
    return 0;
}
