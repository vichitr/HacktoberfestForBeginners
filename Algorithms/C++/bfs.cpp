#include <bits/stdc++.h>
using namespace std;

void bfs(int src, map<int, list<int>> m)
{
    map<int, bool> visited;
    queue<int> q;

    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (int c : m[node])
        {
            if (!visited[c])
            {
                q.push(c);
                visited[c] = true;
            }
        }
    }
}

// bfs for smallest dist from src
void bfsdist(int src, map<int, list<int>> m)
{
    map<int, int> dist;
    queue<int> q;

    for (auto c : m)
    {
        dist[c.first] = INT_MAX;
    }
    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        int node = q.front();
        //   cout<<node<<" ";
        q.pop();
        for (int c : m[node])
        {
            if (dist[c] == INT_MAX)
            {
                q.push(c);
                dist[c] = dist[node] + 1;
            }
        }
    }

    for (auto c : m)
    {
        cout << "NODE " << c.first << " dist " << dist[c.first] << endl;
    }
}

void solve()
{

    map<int, list<int>> m;
    int n = 6;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        m[x].push_back(y);
        m[y].push_back(x);
    }

    // bfs(0,m);

    bfsdist(0, m);
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
