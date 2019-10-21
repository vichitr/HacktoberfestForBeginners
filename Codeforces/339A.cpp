//339A - Helpful Maths
//Author : wgarcia1309

#include<stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    char s[101];
    int m[100],ind=0;
    memset (s,'+',101);
    scanf("%s",s);
    for(int i=0;i<101;i++){
        if(s[i]!='+' && (int)s[i]!=0){
            m[ind]=(int)s[i]-48;
            ind++;
        }
    }
    sort(m,m+ind);
    for(int i=0;i<ind-1;i++){
        printf("%d+",m[i]);
    }
    printf("%d",m[ind-1]);
    return 0;
}