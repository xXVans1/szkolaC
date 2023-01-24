#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 150

// Porownuje 2 linie tekstu
int compare(const void *a, const void *b) {
  const char *line1 = *(const char **)a;
  const char *line2 = *(const char **)b;
  return strcmp(line1, line2);
}

int main() {
  char *lines[MAX_LINES];  //ciag lini
  char buffer[MAX_LINES];  // buffer do czytania lini

  int num_lines = 0;  //ilosc przeczytnych lini

 
  printf("Wprowadz zdanie JEDNO na linie, tznkiedy chcemy zakonczyc zdanie oddzielamy je spacja!: :\n");
  while (fgets(buffer, sizeof(buffer), stdin) != NULL) {

    if (buffer[0] == '\n') continue;
      int valid = 1;
      for (int i = 0; i < strlen(buffer); i++) {
          if (!isalpha(buffer[i]) && !isspace(buffer[i])) {
              valid = 0;
              break;
          }
      }
      if (!valid) {
          printf("Prosze wprowadzic tylko litery!.\n");
          continue;
      }

    lines[num_lines] = malloc(strlen(buffer) + 1);


    strcpy(lines[num_lines], buffer);


    num_lines++;
  }

  // sortowanie
  qsort(lines, num_lines, sizeof(char *), compare);


  printf("\nSorted lines of text:\n");
  for (int i = 0; i < num_lines; i++) {
    printf("%s", lines[i]);
  }

  return 0;
}

