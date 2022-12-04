#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{-1, 1, 2, 6, 4};
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		int ans = N < 5 ? A[N] : 0;
		cout << ans << "\n";
	}
	return 0;
}
