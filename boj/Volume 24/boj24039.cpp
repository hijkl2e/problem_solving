#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		6, 15, 35, 77, 143, 221, 323, 437, 667, 899,
		1147, 1517, 1763, 2021, 2491, 3127, 3599, 4087,
		4757, 5183, 5767, 6557, 7387, 8633, 9797, 10403
	};
	int N{};
	cin >> N;
	int ans = *upper_bound(A.begin(), A.end(), N);
	cout << ans << "\n";
	return 0;
}
