#include<vector>
#include<algorithm>

class DSU {
    int n;
  public:
    vector<int> par;
    vector<long long> rank;

    explicit DSU(int _n) : n(_n) {
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            rank[i] = 1;
        }
    }

    DSU(vector<long long>& _rank) {
        rank = _rank;
        n = rank.size();
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }

    int Root(int x) {
        return x == par[x] ? x : par[x] = Root(par[x]);
    }

    bool Unite(int x, int y) {
        x = Root(x);
        y = Root(y);
        if (x == y) return true;
        if (rank[x] > rank[y]) {
            par[y] = x;
            rank[x] += rank[y];
        } else if (rank[y] > rank[x]) {
            par[x] = y;
            rank[y] += rank[x];
        } else {
            par[x] = y;
            rank[y]++;
        }
        return false;
    }

    int Count() {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (Root(i) == i) cnt++;
        }
        return cnt;
    }
};
