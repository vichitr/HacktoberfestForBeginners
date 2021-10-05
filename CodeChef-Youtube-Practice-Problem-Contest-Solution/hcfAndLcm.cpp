
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, x, y, temp, hcf, lcm;
    cin >> x >> y;
    a = x;
    b = y;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    hcf = a;
    lcm = (x * y) / hcf;
    cout << hcf << " " << lcm;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int fnum, snum, gcd, lcm;
    cin >> fnum;
    cin >> snum;

    for (int i = 1; i <= fnum && i <= snum; i++)
    {
        if (fnum % i == 0 && snum % i == 0)
            gcd = i;
    }
    lcm = fnum * snum / gcd;
    cout << gcd << " " << lcm;
    return 0;
}