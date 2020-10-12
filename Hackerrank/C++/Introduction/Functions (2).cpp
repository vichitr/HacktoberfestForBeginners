#include <iostream> 
 using namespace std ; 
int gre_num (int a, int b, int c , int d ) {
    if (a>b && a>c && a>d ) 
        return a ; 
else if (b>a && b>c && b>d ) 
    return  b ; 
else if (c>a && c>b && c>d ) 
    return  c ; 
else 
    return d ; 
} 

int main () 
{ 
int a,b,c,d ; 
cin >> a ; 
cin >> b ; 
cin >> c ; 
cin >> d ; 
cout <<  gre_num (a,b,c,d) ;     
}
