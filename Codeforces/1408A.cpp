// Codeforces 2020
// Narapureddy Srikanth 02.10.2020
// Circle Coloring : Problem 1408A


#include<bits/stdc++.h>
using namespace std;

#define GO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int

const int maxr = 1e2 + 5;
int arr[3][maxr];

int32_t main()
{
	GO;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < n; i++) {
				cin >> arr[j][i];
			}
		}

		vector<int> ans(n);
		ans[0] = arr[0][0];
		for (int i = 1; i < n; i++) {
			if (i == n - 1) {
				for (int j = 0; j < 3; j++) {
					if (ans[i - 1] != arr[j][i] && ans[0] != arr[j][i])
						ans[i] = arr[j][i];
				}
			}
			else {
				for (int j = 0; j < 3; j++) {
					if (ans[i - 1] != arr[j][i])
						ans[i] = arr[j][i];
				}
			}
		}
		for (auto x : ans)
			cout << x << " ";
		cout << endl;
	}
	return 0;
}

//!