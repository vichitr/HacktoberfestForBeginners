#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main()
{
    int n;
    
    scanf("%d",&n);
    int arr[n];
    int arr_i;
    
    for(arr_i = 0; arr_i < n; arr_i++)
    {
       scanf("%d",&arr[arr_i]);
    }
    float a=0 ,b=0 ,c=0 ;
    for(arr_i = 0; arr_i < n; arr_i++)
      {  if(arr[arr_i]> 0)
         {a += 1;} 
       
        else if(arr[arr_i]<0)
        {b += 1;}
       
        else
        {c += 1;}
      }
       printf("%f\n%f\n%f\n", a/n, b/n, c/n);

    return 0;
}
