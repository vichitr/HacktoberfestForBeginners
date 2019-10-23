#include <stdio.h>
#include <omp.h> //openmp library

long fib(long n) 
{
  long i, j;

  if (n < 2)
    return n;
  else if (n < z) 
  {
    return fib(n-1) + fib (n-2);
  }
  else 
  {
    #pragma omp parallel sections
    {
      #pragma omp section
      i = fib(n-1);
      #pragma omp section
      j = fib(n-2);
    }
    return i + j;
  }
}



int main() {
    int i, n, t = 0, t1 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (i = 1; i <= n; ++i) {
        printf("%d, ", t);
        nextTerm = t + t1;
        t = t1;
        t1 = nextTerm;
    }
    return 0;
}
