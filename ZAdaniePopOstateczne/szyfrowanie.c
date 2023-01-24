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




/*


#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

double stack[MAX_STACK_SIZE];
int num_args = 0;

void push(double x) {
  if (num_args >= MAX_STACK_SIZE) {
    printf("Error: maximum stack size exceeded.\n");
    return;
  }
  stack[num_args++] = x;
}

double pop(void) {
  if (num_args == 0) {
    printf("Error: stack is empty.\n");
    return 0;
  }
  return stack[--num_args];
}

int main(void) {
  printf("Enter an arithmetic operation in inverse Polish notation (e.g. 2 3 +): ");

  double x, y;
  char op;
  while (scanf("%lf %lf %c", &x, &y, &op) == 3) {
    push(x);
    push(y);
    if (op == '+') {
      push(pop() + pop());
    } else if (op == '-') {
      y = pop();
      x = pop();
      push(x - y);
    } else if (op == '*') {
      push(pop() * pop());
    } else if (op == '/') {
      y = pop();
      x = pop();
      push(x / y);
    } else {
      printf("Error: invalid operator.\n");
      return 1;
    }
  }

  printf("Result: %lf\n", pop());

  return 0;
}

*/




//ODWROTNA NOTACJA POLSKA INNE ZADANIE


/*


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100

double stack[MAX_STACK_SIZE];
int num_args = 0;

void push(double x) {
  if (num_args >= MAX_STACK_SIZE) {
    printf("Error: maximum stack size exceeded.\n");
    return;
  }
  stack[num_args++] = x;
}

double pop(void) {
  if (num_args == 0) {
    printf("Error: stack is empty.\n");
    return 0;
  }
  return stack[--num_args];
}

int main(void) {
  printf("Enter an arithmetic operation in inverse Polish notation (e.g. 2 3 +): ");

  char wyr[MAX_STACK_SIZE];
  while (scanf("%s", wyr) == 1) {
    if (isdigit(wyr[0]) || (wyr[0] == '-' && isdigit(wyr[1]))) {
      // Input is a number
      push(atof(wyr));
    } else if (!strcmp(wyr, "+")) {
      // Addition operator
      double y = pop();
      double x = pop();
      push(x + y);
    } else if (!strcmp(wyr, "-")) {
      // Subtraction operator
      double y = pop();
      double x = pop();
      push(x - y);
    } else if (!strcmp(wyr, "*")) {
      // Multiplication operator
      push(pop() * pop());
    } else if (!strcmp(wyr, "/")) {
      // Division operator
      double y = pop();
      double x = pop();
      push(x / y);
    } else if (!strcmp(wyr, "=")) {
      // Print result and clear stack
      printf("Result: %lf\n", pop());
      num_args = 0;
    } else if (!strcmp(wyr, "q")) {
      // Quit calculator
      break;
    } else {
      printf("Error: invalid operator.\n");
      return 1;
    }
  }

  return 0;
}



*/


//CALKOWANIE




/*

#include <stdio.h>
#include <stdlib.h>

// Function prototype
double f(double x);

// Comparison function for qsort()
int compare(const void *a, const void *b) {
  double x = *(double *)a;
  double y = *(double *)b;
  if (x < y) {
    return -1;
  } else if (x > y) {
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char **argv) {
  // Read function from user input
  printf("Enter a function to integrate (e.g. x^2 + 3*x + 1): ");
  char func[256];
  scanf("%s", func);

  // Read integration range from user input
  printf("Enter lower bound of integration range: ");
  double a;
  scanf("%lf", &a);
  printf("Enter upper bound of integration range: ");
  double b;
  scanf("%lf", &b);

  // Set step size for integration
  const int N = 1000;
  double h = (b - a) / N;

  // Perform definite integral using the trapezoid rule
  double sum = 0.5 * (f(a) + f(b));
  for (int i = 1; i < N; i++) {
    sum += f(a + i * h);
  }
  sum *= h;

  // Print result
  printf("Definite integral of %s from %lf to %lf: %lf\n", func, a, b, sum);

  // Read numbers from user input and store in array
  printf("Enter some real numbers, one per line (enter 'q' to quit):\n");
  double numbers[256];
  int num_numbers = 0;
  while (1) {
    char line[256];
    if (fgets(line, sizeof(line), stdin) == NULL) break;
    if (line[0] == 'q') break;
    numbers[num_numbers++] = atof(line);
  }

  // Sort numbers in ascending or descending order based on main function call parameter
  int ascending = 1;
  if (argc > 1 && strcmp(argv[1], "-d") == 0) {
    ascending = 0;
  }
  qsort(numbers, num_numbers, sizeof(double), ascending ? compare : rcompare);

  // Print sorted numbers
  printf("Sorted numbers:\n");
  for (int i = 0; i < num_numbers; i++) {
    printf("%lf\n", numbers[i]);
  }

  return 0;
}

// Example function to integrate
double f(double x) {
  return x * x + 3 * x + 1;
}

*/