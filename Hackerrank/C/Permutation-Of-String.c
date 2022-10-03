#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
    int i=n-1,j=n-1;
    while(i>0&&strcmp(s[i-1],s[i])>=0)
    i--;
    if(i<=0)
        return 0;
    
    while(strcmp(s[i-1],s[j])>=0)
    j--;
    
    char*t=s[i-1];
    s[i-1]=s[j];
    s[j]=t;
    
    j=n-1;
    while(i<j)
    {
        t=s[i];
        s[i]=s[j];
        s[j]=t;
        i++;
        j--;
    }
    return 1;
}

int main()
