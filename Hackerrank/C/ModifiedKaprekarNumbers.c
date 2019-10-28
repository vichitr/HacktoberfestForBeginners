#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
  long i;int check=0;
  int cnt=0;  long sum1=0,sum2=0; 


     for(i=p;i<=q;i++)
         {long sq=pow(i,2);
        
          long a=sq,b=sq;
          cnt=0;sum1=sum2=0;
          int flag=1;int mult1=0,mult2=0;

          while(a>0)
            {a=a/10;
             cnt=cnt+1;}

             
          while(b>0)
             {int rem=b%10;
              b=b/10;
              
              if(flag<=floor((cnt+1)/2))
                 {sum1=sum1+(rem*pow(10,mult1));
                  flag+=1;mult1++;continue;}
                  
              if(flag>floor((cnt+1)/2)&&flag<=cnt)
                 {sum2+=rem*pow(10,mult2);
                  flag+=1;mult2++;}}
            int tot=sum1+sum2;
            
            if((tot==i)&&(tot%100!=0)&&(tot!=10))
               {printf("%d ",i);
                check++;}}
            
               
            
            if(check==0)
               printf("INVALID RANGE");
                 

       
          


}

int main()
{
    char* p_endptr;
    char* p_str = readline();
    int p = strtol(p_str, &p_endptr, 10);

    if (p_endptr == p_str || *p_endptr != '\0') { exit(EXIT_FAILURE); }

    char* q_endptr;
    char* q_str = readline();
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    kaprekarNumbers(p, q);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}
