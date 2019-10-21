//349A - Cinema Line
//Author : wgarcia1309
#include <iostream>
using namespace std;
int main() {
  int n,m[100001],change[3];
  change[0]=change[1]=change[2]=0;
  cin>>n;
  bool x=true;
  for(int i=0;i<n;i++){
    cin>>m[i];
    if((m[i])/25==1 && x){
      change[0]++;
    }else if(x){
      if((m[i])/25==2){
        if(change[0]<=0)x=false;
        change[0]--;
        change[1]++;
      }else{
        if(change[0]>0 && change[1]>0){
          change[0]--;
          change[1]--;
          change[3]++;
        }else if (change[0]>2){
          change[0]-=3;
          change[3]++;
        }else{
          x=false;
        }
      }
  }
  }
  if(x)cout << "YES\n";
  else cout << "NO\n";
}