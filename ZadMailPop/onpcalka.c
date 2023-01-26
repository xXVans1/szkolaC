#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define STOS_MAX_SIZE 1000

typedef struct Stos {
    double values[STOS_MAX_SIZE];
    int top;
} Stos;

Stos* stworzStos() {
    Stos* stos = (Stos*) malloc(sizeof(Stos));
    stos->top = 0;
    return stos;
}

void push(Stos* stack, double value) {
    if (stack->top == STOS_MAX_SIZE) {
        printf("Przepelnienie stosu!!\n");
    } else {
        stack->values[stack->top++] = value;
    }
}

double pop(Stos* stos) {
    if (stos->top == 0) {
        printf("Stos jest niedopelniony!\n");
        return 0;
    } else {
        return stos->values[--stos->top];
    }
}

void oproznijStos(Stos* stos) {
    free(stos);
}

double evaluate(char* expr, double x) {
    int i, len = strlen(expr);
    Stos* stos = stworzStos();

    for (i = 0; i < len; i++) {
        char exp = expr[i];

        if (isdigit(expr[i])) {
            push(stos, atof(&expr[i]));
            while (isdigit(expr[i]) || expr[i] == '.') i++;
            i--;
        } else if (exp == 'x') {
            push(stos, x);
        } else if (exp == '+') {
            double x2 = pop(stos);
            double x1 = pop(stos);
            push(stos, x1 + x2);
        } else if (exp == '-') {
            double x2 = pop(stos);
            double x1 = pop(stos);
            push(stos, x1 - x2);
        } else if (exp == '*') {
                double x2 = pop(stos);
                double x1 = pop(stos);
                push(stos, x1 * x2);
            } else if (exp == '/') {
                double x2 = pop(stos);
                double x1 = pop(stos);
                push(stos, x1 / x2);
            } else if (exp == '^') {
                double x2 = pop(stos);
                double x1 = pop(stos);
                push(stos, pow(x1, x2));
            }
    }
    double wynik = pop(stos);
    oproznijStos(stos);
    return wynik;
}

int main() {
    char func[STOS_MAX_SIZE];
    double xstart, xend, dx;

    printf("Podaj wzor funkcji w ONP: ");
    fgets(func, STOS_MAX_SIZE, stdin);
    printf("Podaj wartosc poczatkowa xend: ");
    scanf("%lf", &xstart);
    printf("Podaj wartosc koncowa xend: ");
    scanf("%lf", &xend);
    printf("Podaj wartosc kroku dx: ");
    scanf("%lf", &dx);

    double x, calka = 0;
    for (x = xstart; x <= xend; x += dx) {
        double y = evaluate(func, x);
        printf("f(%.2lf) = %.2lf\n", x, y);
        calka += y * dx;
    }
    printf("Wynik = %.2lf\n", calka);
    return 0;
}
