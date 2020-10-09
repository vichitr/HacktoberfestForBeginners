// code by yctseng1227
#include <iostream>
using namespace std;
 
#define MAXN 200005
 
int calc(int a, int b){
    int tmp1 = a / 3;
    int tmp2 = min(a, b);
    int tmp3 = b / 3;

    return max(a/3+b/3,
    tmp2+(a-tmp2)/3+(b-tmp2)/3);
}
int main()
{
    int _case, n, x;
    cin >> _case;
    while(_case--){
        cin >> n;

        int cnt[3] = {};
        for(int i=0; i<n; i++){
            cin >> x;
            cnt[x % 3]++;
        }
        cout << cnt[0] + calc(cnt[1], cnt[2]) << endl;
    }
    return 0;
}
