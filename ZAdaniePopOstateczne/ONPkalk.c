#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_STOS_SIZE 1024

double stos[MAX_STOS_SIZE];
int num_args = 0;

void push(double x) {       //dodanie na stos
    if (num_args >= MAX_STOS_SIZE) {
        printf("Limit stosu przepełniony!\n");
        return;
    }
    stos[num_args++] = x;
}

double pop() {      //usuniecie ze stosu
    if (num_args == 0) {
        printf("Stos jest pusty!\n");
        return 0;
    }
    return stos[--num_args];
}

int main() {
    printf("Aby program działał poprawnie po wpisaniu operator/liczby NACISNIJ ENTER, nastepnie wprowadz nastepna liczbe/operator i nacisnij enter\n");
    printf("Gdy wpiszesz już całe działanie wpisz '=' i nacisnij enter\n");
    printf("Przykładowe działanie: 2 ENTER 4 ENTER + ENTER = ENTER \n");
    printf("DOSTEPNE OPERATORY: +, -, *, /, ^, =\n");
    printf("Aby wyjść z programu wpisz q\n");
    printf("Podaj dzialanie w ONP: ");

    char wyr[MAX_STOS_SIZE];
    while (scanf("%s", wyr) == 1) {
        if (isdigit(wyr[0]) || (wyr[0] == '-' && isdigit(wyr[1]))) {

            push(atof(wyr));
        }
        else if (!strcmp(wyr, "+")) {

            double y = pop();
            double x = pop();
            push(x + y);
        }
        else if (!strcmp(wyr, "-")) {

            double y = pop();
            double x = pop();
            push(x - y);
        }
        else if (!strcmp(wyr, "*")) {

            push(pop() * pop());
        }
        else if (!strcmp(wyr, "/")) {

            double y = pop();
            double x = pop();
            push(x / y);
        }
        else if(!strcmp(wyr, "^"))
        {
            double y = pop();
            double x = pop();
            push(pow(x, y));
        }
        else if (!strcmp(wyr, "=")) {

            printf("Wynik: %lf\n", pop());
            num_args = 0;
        }
        else if (!strcmp(wyr, "q")) {

            break;
        } else {
            printf("Nieprawidłowy operator!\n");
            return 1;
        }
    }

    return 0;
}