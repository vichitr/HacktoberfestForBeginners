#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_front(0);
    dq.pop_back();
    dq.pop_front();
    for( auto el:dq){
        cout<<el<<endl;
    }
}