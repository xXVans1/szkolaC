#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N_MAX 100

float tekst[N_MAX];

//funkcja porownujaca ciagi znakow
int compare(const void *a, const void *b) {
    return *(float *) a - *(float *) b;
}

int main(int argc, char *argv[]) {
    int rosnaco = 1;
    while (1) {
        int n = 0;
        char choice;
        printf("Wybierz czy chceswz sortowac rosnaco czy malejaco? (r-rosnaco/m-malejaco): ");
        choice = getchar();
        if (choice == 'm') rosnaco = 0;
        char buf[1024];

        printf("Wprowadź ciąg liczb rzeczywistych, każddy ciąg rozdziel Enterem,np: 245 ENTER 23.54 ENTER 14 ENTER, a na koncu zakoncz program znacznikiem kónca pliku: ");

        while (fgets(buf, sizeof(buf), stdin)) {
            if (buf[strlen(buf) - 1] == '\n') buf[strlen(buf) - 1] = 0; //sprawdzenie pustcyh znakow
            if (strlen(buf) == 0) continue;

            int valid = 1;
            for (int i = 0; i < strlen(buf); i++) {
                if (!isdigit(buf[i]) && buf[i] != '.' && buf[i] != '-') {
                    valid = 0;
                    break;
                }
            }

            if (!valid) {
                printf("Zły input, podaj tylko liczby!\n");
                continue;
            }

            tekst[n] = atof(buf);
            n++;
        }

        if (rosnaco) {
            qsort(tekst, n, sizeof(float), compare);   //sortowanie rosnaca lub malejaca (zalezy od parametru wpisanego w konsolii -m)
        } else {
            qsort(tekst, n, sizeof(float), compare);
            for(int i = 0; i< n / 2; i++){
                float temp = tekst[i];
                tekst[i] = tekst[n -i -1];
                tekst[n - i - 1]= temp;
            }
        }

        for (int i = 0; i < n; i++) {
            printf("%.3f\n", tekst[i]);
        }
    }
    return 0;
}