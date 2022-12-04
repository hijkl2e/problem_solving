#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int K{};
		cin >> K;
		int ans{};
		vector<int> A;
		for (int i = 0; i < 20; ++i) {
			int x{};
			cin >> x;
			auto it = upper_bound(A.begin(), A.end(), x);
			ans += i - (it - A.begin());
			A.insert(it, x);
		}
		cout << K << " " << ans << "\n";
	}
	return 0;
}
