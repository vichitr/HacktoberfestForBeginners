#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::vector;
using std::swap;
vector<vector<int>> adj,J,L,height;
vector<int> K,tempJ,tempL;
int n,max;
void show(int ty,int k=0)
{
    if(ty==0)
    {
        cout << "height::\n";
        for(int i = 0;i < height[k].size();i++)
        {
            cout << height[k][i] << " ";
        }
        cout << "\n";
    }
    else if(ty==1)
    {
        cout << "\nadj::\n";
        for(int i = 1;i <= n;i++)
        {
            for(int j = 0;j < adj[i].size();j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    else if(ty==2)
    {
        cout << "/nresize::\n";
        for(int i = 0;i < max;i++)
        {
            cout << J[height[i][0]].size() << " " << L[height[i][0]].size() << "\n";
        }
        cout << "\n";
    }
    else if(ty==3)
    {
        cout << "\n" << k << ": \nJ: ";
        for(int i = 0;i < J[k].size();i++)
        {
            cout << J[k][i] << " ";
        }
        cout << "\nL: ";
        for(int i = 0;i < L[k].size();i++)
        {
            cout << L[k][i] << " ";
        }
        cout << "\n";
    }
    int temp;
    cin >> temp;
}
void setparentinchildof(int nod)
{
    for(int i = 1;i < adj[nod].size();i++)
    {
        int cnod = adj[nod][i];
        if(cnod==adj[nod][0])
        {
            swap(adj[nod][i],adj[nod][adj[nod].size()-1]);
            adj[nod].pop_back();i--;
        }
        else
        {
            adj[cnod][0]=nod;
        }
    }
}
void pushchildinheight(int nod,int curr)
{
    for(int i = 1;i < adj[nod].size();i++)
    {
        int cnod = adj[nod][i];
        height[curr].push_back(cnod);
    }
}
void set()
{
    height.push_back(vector<int>(1,1));
    height.push_back(vector<int>(0));
    int i = 0;
    while(true)
    {
        int curr = i;
        for(int j = 0;j < height[curr].size();j++)
        {
            int hnod = height[curr][j];
            setparentinchildof(hnod);
            pushchildinheight(hnod,curr+1);
        }
        if(height[curr+1].size()==0)
        {
            max=curr+1;
            break;
        }
        else
        {
            height.push_back(vector<int>(0));
            i++;
        }
    }
}
int Jh(int curr)
{
    return max-curr;
}
int Lh(int curr)
{
    return curr+1;
}
void resizeJL()
{
    J.resize(n+1);
    L.resize(n+1);
    for(int i = 0;i < max;i++)
    {
        for(int j = 0;j < height[i].size();j++)
        {
            J[height[i][j]].resize(Jh(i),0);
            L[height[i][j]].resize(Lh(i),0);
        }
    }
    tempJ.resize(max+1);
    tempL.resize(max+1);
}
void fillemptyL(int h)
{
    for(int i = 0;i < height[h].size();i++)
    {
        int nod = height[h][i];
        L[nod].assign(Lh(h),K[nod]);
    }
}
void push(int h)
{
    for(int i = 0;i < height[h].size();i++)
    {
        int curr = h;
        int pnod = height[h][i];
        int cnod = height[h][i];
        while(curr >= 0)
        {
            J[pnod][h-curr] += L[cnod][h-curr];
            pnod = adj[pnod][0];
            curr--;
        }
    }
}
void fillzeroJ()
{
    for(int i = 0;i <= max;i++)
    {
        for(int j = 0;j < height[i].size();j++)
        {
            int nod = height[i][j];
            J[nod].assign(J[nod].size(),0);
        }
    }
}
void summation(int nod,int curr)
{
    int Ll = Lh(curr);
    for(int i = 0;i < Ll;i++)
    {
        tempL[i]=0;
        for(int j = 1;j < adj[nod].size();j++)
        {
            int cnod = adj[nod][j];
            tempL[i]+=L[cnod][i];
        }
    }
    int Jl = Jh(curr);
    for(int i = 0;i < Jl;i++)
    {
        tempJ[i]=0;
        for(int j = 1;j < adj[nod].size();j++)
        {
            int cnod = adj[nod][j];
            tempJ[i]+=J[cnod][i];
        }
    }
}
void fillL(int nod,int curr)
{
    summation(nod,curr);
    for(int l = 0;l < L[nod].size();l++)
    {
        int sum1 = 0;
        int sum2 = 0;
        sum1 = K[nod] + (curr+1+(K[nod]^l)<max?tempJ[K[nod]^l]:0);
        sum2 = tempL[l];
        L[nod][l] = sum1<sum2?sum2:sum1;
    }
}
void setJL()
{
    resizeJL();
    fillzeroJ();
    fillemptyL(max-1);
    push(max-1);
    for(int i = max-2;i >= 0;i--)
    {
        int curr = i;
        for(int k = 0;k < height[curr].size();k++)
        {
            int nod = height[curr][k];
            fillL(nod,curr);
        }
        push(i);
    }

}
int main()
{
    cin >> n;
    if(n==0)
    {
        cout << 0 << "\n";
        return 0;
    }
    K.resize(n+1);
    adj.resize(n+1,vector<int>(1,0));
    for(int i = 1;i <= n;i++)
    {
        cin >> K[i];
    }
    for(int i = 1;i <= n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    set();
    setJL();
    cout << J[1][0];
}
