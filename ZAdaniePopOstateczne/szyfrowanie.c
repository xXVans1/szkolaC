#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv) {
  if (argc < 2) {
    printf("ERROR, Nie podano azwy pliku!\n");
    return 1;
  }

  // Open file for binary reading
  FILE *file1, *file2;
  char password[256];
  int password_length;

  file1 = fopen(argv[1], "rb");
  if (file1 == NULL) {
    printf("Nie mozna otworzyć pliku do otczytu!\n");
    return 1;
  }


  char temp[] = "tempfileXXXXXX";
  int fd = mkstemp(temp);
  if (fd == -1) {
    printf("Nie mozna stworzyć pliku tymczsowego!\n");
    return 1;
  }

  // Open temporary file for binary writing
  file2 = fdopen(fd, "wb");
  if (file2 == NULL) {
    printf("Error: failed to open temporary file for writing.\n");
    return 1;
  }


  printf("Podaj haslo: ");

  scanf("%s", password);
  password_length = strlen(password);


  int j = 0;
  int sign;
  while ((sign = getc(file1)) != EOF) {
    sign ^= password[j % password_length];
    putc(sign, file2);
    j++;
  }

  fclose(file2);
  fclose(file1);

  unlink(argv[1]);
  rename(temp, argv[1]);

  return 0;
}




