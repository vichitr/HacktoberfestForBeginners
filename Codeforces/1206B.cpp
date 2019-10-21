#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using LL =long long;

int main(){
  LL n,ele,noof0=0;
  cin>>n;
  vector<LL> pos,neg;
  LL nsum=0,psum=0;
  for(int i=0;i<n;i++)
  { 
   cin>>ele;
   if(ele<0)neg.push_back(ele);
   else if(ele>0)pos.push_back(ele);
   else nsum++,noof0++;
  }
  for(auto a:neg)nsum+=-a-1;
  for(auto a:pos)psum+=a-1;
  
  if(neg.size()%2==0)
        cout<< nsum+psum;
  else
  { 
      if(noof0)
        cout<<nsum+psum;
   else
        cout<<nsum+psum+2;
  }
  
  
}
      
