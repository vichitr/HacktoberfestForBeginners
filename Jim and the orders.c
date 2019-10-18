#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,min;
    scanf("%d",&n);
    int order[n],prep[n],sum[n],fal[n],cu[n];
    for(int i=0;i<n;i++)
    {
    scanf("%d%d",&order[i],&prep[i]);
     sum[i]=order[i]+prep[i];
     fal[i]=order[i]+prep[i];
     
     }
     
     for(int j=0;j<n;j++)
     {
         for(int k=0;k<=n-2;k++)
         {
             int temp=0;
             if(sum[k]>sum[k+1])
             {
              temp=sum[k];
              sum[k]=sum[k+1];
              sum[k+1]=temp;  
             }
         }
     }
     int v=0;
     cu[v]=sum[0];
     for(int c=0;c<=n-2;c++)
     {
     if(sum[c]==sum[c+1])
     cu[v]=sum[c+1];
     else
     {
         v++;
         cu[v]=sum[c+1];
     }
     }
     for(int g=0;g<=v;g++)
     {
         for(int f=0;f<n;f++)
         {
             if(cu[g]==fal[f])
             printf("%d ",f+1);
         }
     }
     return 0;
}
   
