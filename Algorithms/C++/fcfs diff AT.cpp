#include<iostream> 
using namespace std; 
void wt(int p[], int n, int b[],int w[], int a[]) 
{ 
    int s[n]; 
    s[0] = 0; 
    w[0] = 0; 
  
    for (int i = 1; i < n ; i++) 
    { 
        s[i] = s[i-1] + b[i-1]; 
  
        w[i] = s[i] - a[i]; 
  
        if (w[i] < 0) 
            w[i] = 0; 
    } 
} 

void tat(int p[], int n, int b[],int w[], int t[]) 
{ 
    for (int i = 0; i < n ; i++) 
        t[i] = b[i] + w[i]; 
} 

void avg(int p[], int n, int b[], int a[]) 
{ 
    int w[n], t[n]; 
  
    wt(p, n, b, w, a); 
  
    tat(p, n, b, w, t); 

    cout << "Process \t\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\tCompletion Time"; 
    float avg1 = 0, avg2 = 0; 
    for (int i = 0 ; i < n ; i++) 
    { 
        avg1 = avg1 + w[i]; 
        avg2 = avg2 + t[i]; 
        int c = t[i] + a[i]; 
        cout<<"\t\t"<<i+1<<"\t\t"<<b[i]<<"\t\t"<<a[i]<<"\t\t"<<w[i]<<"\t\t"<<t[i]<<"\t\t"<<c; 
    } 
  
    cout << "Average waiting time: "<< avg1 / n; 
    cout << "Average turn around time: "<< avg2 / n; 
} 

int main() 
{ 
    int p[] = {1, 2, 3}; 
    int n = sizeof p / sizeof p[0]; 
  
    int x[] = {5, 9, 6}; 
  
    int y[] = {0, 3, 6}; 
  
    avg(p, n, x, y); 
  
    return 0; 
}
