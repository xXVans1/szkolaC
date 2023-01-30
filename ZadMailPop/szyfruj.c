#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Niepoprawna liczba argumentów\n");
        return 1;
    }

    char haslo[256];
    printf("Podaj hasło: ");
    scanf("%s", haslo);
    int dlugosc_hasla = strlen(haslo);

    FILE *file1, *file2;
    if (NULL==(file1=fopen(argv[1],"rb"))) {
        printf("Nie można otworzyć pliku do odczytu.\n");
        return 1;
    }
    char tymczasowy[] = "tymczasowy.dat";
    if (NULL==(file2=fopen(tymczasowy,"wb"))) {
        printf("Nie można otworzyć pliku tymczasowego do zapisu.\n");
        return 1;
    }

    int j = 0;
    int znak;
    while ((znak = getc(file1)) != EOF) {
        znak ^= haslo[ j % dlugosc_hasla ];
        putc(znak, file2);
        j++;
    }

    fclose(file1);
    fclose(file2);

    if (remove(argv[1]) != 0) {
        printf("Nie można usunąć pliku.\n");
        return 1;
    }
    if (rename(tymczasowy, argv[1]) != 0) {
        printf("Nie można zmienić nazwy pliku tymczasowego.\n");
        return 1;
    }

    return 0;
}
