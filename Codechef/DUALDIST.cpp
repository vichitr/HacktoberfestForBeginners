#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long int
#define ld long double

const int MOD = 1e9 + 7;

const int mx_rng = 1e5 + 10;
const int lg = 16;
vector<int> tr[mx_rng];
int pr[mx_rng][lg];
int lvl[mx_rng];
ll in[mx_rng];
ll in_cnt[mx_rng];
ll out[mx_rng];
ll out_cnt[mx_rng];

int lca(int u, int  v){
    if(u==v)return u;
    if(lvl[u] < lvl[v]){
         int tmp = u;
        u = v;
        v = tmp;
    }

    for(int i=lg-1;i>=0;i--){
        if(lvl[pr[u][i]] >= lvl[v]){
            u = pr[u][i];
        }
    }
    if(u==v)return u;
    for(int i=lg-1;i>=0;i--){
        if(pr[u][i] != pr[v][i]){
            u = pr[u][i];
            v = pr[v][i];
        }
    }
    return pr[u][0];
}

int lift(int a, int d){
    for(int i=lg-1;i>=0;i--){
        if((d - (1<<i)) >= 0){
            d -= 1<<i;
            a = pr[a][i];
        }
    }
    return a;
}

template<typename T>
void print_arr(T arr[], int l=-1, int r=-1){
    if(l==-1)l=0;
     if(r==-1)l=sizeof(arr)/sizeof(arr[0]);
    for(int i=l;i<r;i++)cout<<arr[i]<<" ";
    cout<<endl;
}

template<typename T>
void print_vec(vector<T> v, int l=-1, int r=-1){
    if(l==-1)l=0;
    if(r==-1)l=v.size();
    for(int i=l;i<r;i++)cout<<v[i]<<" ";
    cout<<endl;
}



void rec(int nd, int p = 0, int l = 1){
    lvl[nd] = l;
    pr[nd][0] = p;
    for(int i=1;i<lg;i++){
        pr[nd][i] = pr[pr[nd][i-1]][i-1];
    }
    for(int i : tr[nd]){
        if(i!=p)rec(i, nd, l+1);
    }
}

void find_in(int nd, int p = 0){
    in_cnt[nd] = 0;
    ll d = 0;
    for(int i : tr[nd]){
        if(i!=p){
            find_in(i, nd);
            in_cnt[nd] += in_cnt[i];
            d += in[i];
        }
    }
     in[nd] = d + in_cnt[nd];
    in_cnt[nd] += 1;
}

void find_out(int nd, int p, int n){
    for(int i : tr[nd]){
        if(i!=p){
            out[i] = out[nd] + in[nd] - (in_cnt[i] + in[i]) + (n - in_cnt[i]);
            find_out(i, nd, n);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n, q, a, b;
        scanf("%d %d", &n, &q);
        for(int i=0;i<n;i++){
            tr[i].clear();
            in[i] = 0;
            lvl[i] = 0;
            out[i] = 0;
            for(int j=0;j<lg;j++)pr[i][j] = 0;
        }
        for(int i=0;i<n-1;i++){
            scanf("%d %d", &a, &b);
            tr[a-1].push_back(b-1);
            tr[b-1].push_back(a-1);
        }
        rec(0);
        find_in(0);
        out[0] = 0;
        find_out(0, 0, n);
        // print_arr(in, 0, n);
        // print_arr(out, 0, n);
            // print_arr(in_cnt, 0, n);
        // print_arr(out_cnt, 0, n);
        // print_arr(lvl, 0, n);
        while(q--){
            scanf("%d %d", &a, &b);
            a--;
            b--;
            if(lvl[a] < lvl[b]){
                int tmp = a;
                a = b;
                b = tmp;
            }
            // cout<<a<<" "<<b<<endl;
            int d = lvl[a] + lvl[b]  - 2*lvl[lca(a, b)];
            // cout<<lca(a, b)<<" "<<d<<endl;
            int nda = lift(a, (d-1)/2);
            int ndb = pr[nda][0];
            // cout<<nda<<" "<<ndb<<endl;
            ll da = in[a] + out[a] - ((n - in_cnt[nda])*(lvl[a] + lvl[ndb]  - 2*lvl[lca(ndb, a)]) + out[ndb] + in[ndb] - (in_cnt[nda] + in[nda]));
            ll db = in[b] + out[b] - ((in_cnt[nda])*(lvl[b] + lvl[nda]  - 2*lvl[lca(nda, b)]) + in[nda]);
            cout<<da+db<<endl;
        }
    }
    
    return 0;
}



