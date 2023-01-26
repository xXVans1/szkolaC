#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct RZYM {
    int arab;
    char *rzym;
};


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

int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}

int RzymskaNaDziesietna(char *rzymska){

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
        return -1;
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
    return n;
}

int DziesietneNaRzymskie(int num)
{
    struct RZYM rz[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    if (num <= 0 || num > 3999)
    {
        printf("Wprowadzono niepoprawną liczbę arabską\n");
        return 1;
    }
    int i = 0;
    while (num > 0)
    {
        if (num >= rz[i].arab)
        {
            printf("%s", rz[i].rzym);
            num = num -  rz[i].arab;
        }
        else
        {
            i++;
        }
    }
    return 0;
}
int main(){
    while (1)
    {
        char user_input[50];
        printf("\nWprowadz liczbe w systemie rzymskim lub arabskim: ");
        scanf("%s", user_input);

       
        int is_roman = 1;
        for (int i = 0; i < strlen(user_input); i++)
        {
            if (!isalpha(user_input[i]))
            {
                is_roman = 0;
                break;
            }
        }

        if (is_roman)
        {
            int result = RzymskaNaDziesietna(user_input);
            if (result == -1)
            {
                printf("Wprowadzono niepoprawną liczbę rzymską\n");
                continue;
            }
            else
            {
                printf("W systemie arabskim: %d\n", result);
            }
        }
        else
        {
            int num = atoi(user_input);
            printf("W systemie rzymskim: ");
            DziesietneNaRzymskie(num);
        }
    }

}
