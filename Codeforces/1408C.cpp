// Codeforces 2020
// Narapureddy Srikanth 02.10.2020
// Discrete Acceleration : Problem 1408C


#include<bits/stdc++.h>
using namespace std;

#define GO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int

const int maxr = 1e5 + 5;
int n, l;
double arr[maxr];

double time_left(double x) {
	double result = 0;
	for (int i = 1; i < n + 2; i++) {
		if (x < arr[i]) {
			result += (x - arr[i - 1]) / (i);
			break;
		}
		result += ((arr[i] - arr[i - 1]) / (i));
	}
	return result;
}

double time_right(double x) {
	double result = 0;
	for (int i = n; i >= 0; i--) {
		if (x > arr[i]) {
			result += (arr[i + 1] - x) / (n - i + 1);
			break;
		}
		result += (arr[i + 1] - arr[i]) / (n - i + 1);
	}
	return result;
}

int32_t main()
{
	GO;
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> l;
		arr[0] = 0; arr[n + 1] = l;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		double low = 0, high = l;
		double ans = 1e18;
		while (low <= high) {
			double mid = (low + high) / 2;
			double left = time_left(mid);
			double right = time_right(mid);
			if (left <= right) {
				ans = min(ans, max(left, right));
				low = mid + 0.0000001;
			}
			else {
				high = mid - 0.0000001;
			}
		}
		cout << fixed << setprecision(10) << ans << endl;
	}
	return 0;
}

//!