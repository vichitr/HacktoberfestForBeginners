// Codeforces 2020
// Narapureddy Srikanth 02.10.2020
// Arrays Sum : Problem 1408B


#include<bits/stdc++.h>
using namespace std;

#define GO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int

const int maxr = 1e2 + 5;
int arr[maxr], grid[maxr][maxr], vec[maxr];

int32_t main()
{
	GO;
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		bool flag = false;
		memset(grid, 0, sizeof(grid));
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (i > 0 && arr[i] != arr[i - 1])
				flag = true;
			int pre = arr[i];
			for (int j = 0; pre > 0; pre--, j++) {
				grid[j][i] = 1;
			}
		}

		if (k == 1) {
			if (flag)
				cout << -1 << endl;
			else
				cout << 1 << endl;
			continue;
		}
		int ans = 1;
		int idx = arr[n - 1] - 1;
		memset(vec, 0, sizeof(vec));
		while (idx >= 0) {
			for (int i = 0; i < n; i++) {
				vec[i] += grid[idx][i];
			}
			int distinct = 1;
			for (int i = 1; i < n; i++) {
				if (vec[i] != vec[i - 1])
					distinct++;
			}
			if (distinct <= k)
				idx--;
			else {
				ans++;
				memset(vec, 0, sizeof(vec));
			}
		}
		cout << ans << endl;
	}
	return 0;
}

//!
