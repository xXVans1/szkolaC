#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x, y, z, pi;
    int i,licznik, powtorzenia; 
    int MAX_R = pow(2,16)-1;
    printf("Podaj ilość powtórzeń: ");
    scanf("%d",&powtorzenia);

    srand(MAX_R);
    licznik= 0;
    for ( i=0; i<powtorzenia; i++) {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      z = x * x + y * y;
      if (z<=1) 
      licznik++;
      }
    pi=(double)licznik/powtorzenia*4;
    printf("Oszacowana wartość pi: %f \n",pi);
    return 0;
}