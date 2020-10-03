#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i,n,back=0,front=0;
    scanf("%d",&n);
    int a[n],x[n];
    for(i=0;i<n;i++)
    {
        x[i]=rand();
    }
    clock_t t;
    t=clock();
    back =x[0];
    for(i=0;i<n;i++)
    {
        a[i]=back;
        front=x[i+1];
        back=(back+front)/(i+1);
    }
    t = clock() -t;
    //for(i=0;i<n;i++)
       //printf("%d ",a[i]);
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nTime Taken By algo:- %lf",time_taken);

    return 0;
}
