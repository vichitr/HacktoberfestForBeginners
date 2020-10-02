
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;
int n, m, k, x, y, z, a, b, c, d, i, j, l, r, f, q;

vector<int> g[N];
int Par[N];
int depth[N];

void dfs(int src, int par)
{
    Par[src] = par;
    for (auto c : g[src])
    {
        if (c != par)
        {
            depth[c] = 1 + depth[src];
            dfs(c, src);
        }
    }
}

//O(n)
int LCA(int x, int y)
{
    if (depth[x] < depth[y])
        swap(x, y);
    while (depth[x] > depth[y])
    {
        x = Par[x];
    }
    while (x != y)
    {
        x = Par[x];
        y = Par[y];
    }
    return x;
}

void sol()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);

    cout << LCA(10, 11) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sol();
    return 0;
}
