#include <bits/stdc++.h>
using namespace std;

int n = 1e6;

class FT
{
public:
  //using 1 based indexing
  vector<int> s;
  FT(int n)
  {
    s.resize(n + 1);
  }
  //i is pos which has to change
  void update(int i, int inc)
  {
    while (i <= n)
    {
      s[i] += inc;
      i += i & (-i);
    }
  }
  //sum of values in [1,i]
  int query(int i)
  {
    int ans = 0;
    while (i > 0)
    {
      ans += s[i];
      i -= i & (-i);
    }
    return ans;
  }
  //min pos s.t. sum of[1,i]>=sum
  int lower_bound(int sum) //returns n if no sum is >=sum || -1 if empty sum
  {
    if (sum <= 0)
      return -1;
    int i = 1;
    for (int pw = 1 << 25; pw; pw >>= 1)
    {
      if (i + pw <= s.size() && s[i + pw - 1] < sum)
        i += pw, sum -= s[i - 1];
    }
    return i;
  }
};

int32_t main()
{
  
  return 0;
}
