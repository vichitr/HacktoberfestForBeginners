#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n,a=0;
    scanf("%d", &n);
    while(n>0){
        a+=n%10;
        n=n/10;
    }
    printf("%d",a);
    return 0;
}
