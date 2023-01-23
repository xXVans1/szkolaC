#include <stdio.h>
#include <string.h>
#include <ctype.h>



int main(){
    int dlSlowa, i;
    char slowo[40], odwrSlowo[40];
    int end = 0;
while(!end){
    printf("\nPodaj slowo: ");
    scanf("%s",&slowo);
    int len = strlen(slowo);
    int valid = 1;
    for (i = 0; i < len; i++) {
        if (!isalpha(slowo[i])) {
            valid = 0;
            break;
        }
    }
    if (!valid) {
        printf("Podaj prawidlowe slowo (tylko z liter)\n");
        continue;
    }
    dlSlowa = strlen(slowo);


    int j = dlSlowa - 1;
    for(i = 0; i<dlSlowa;i++) {
        odwrSlowo[i] = slowo[j];
        j--;
    }



        if(!strcmp(slowo,odwrSlowo))
            printf("\nTo jest palindrom");
        else
            printf("\nTo nie jest palindrom");
    char choice;
    printf("\nCzy chcesz kontynuowac? (T/N) : ");
    scanf(" %c", &choice);
    if(toupper(choice) == 'N')
        end = 1;
}
    return 0;

}
