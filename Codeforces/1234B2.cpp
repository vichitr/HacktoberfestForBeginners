#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define sort_ar() sort(ar.begin(), ar.end());
#define sort_ar_inv() sort(ar.begin(), ar.end(), greater<>());
#define FAST_IOS() ios_base::sync_with_stdio(false);
#define FAST_CIN() cin.tie(0);
#define FAST_COUT() cout.tie(0);
#define MOD 10000007
 
typedef long long ll;
const int INF = 0x3f3f3f3f;
 
int k, n;
 
std::deque<int> q;
std::set<int> s;
 
void add(int ent){
 
    if(s.find(ent) == s.end()){
        if(q.size() < k){
            s.insert(ent);
            q.emplace_front(ent);
        } else {
            s.erase(q.back());
            q.pop_back();
 
            s.insert(ent);
            q.emplace_front(ent);
        }
    }
}
 
int main(){
    FAST_IOS();
    FAST_CIN();
    FAST_COUT();
 
    cin >> n >> k;
    
    for(int i = 0, ent; i < n; i++){
        cin >> ent;
        add(ent);
    }
 
    cout << q.size() << "\n";
    for(auto i : q){
        cout << i << " ";
    }
 
    cout << "\n";
    
    return 0;
}
 