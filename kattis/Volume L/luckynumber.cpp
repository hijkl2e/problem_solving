#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		-1, -1, 45, 150, 375, 750, 1200, 1713, 2227, 2492, 2492, 2225,
		2041, 1575, 1132, 770, 571, 335, 180, 90, 44, 18, 12, 6, 3, 1
	};
	int N{};
	cin >> N;
	int ans = N < 26 ? A[N] : 0;
	cout << ans << "\n";
	return 0;
}
