#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 3;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A;
		int sum{};
		while (N--) {
			int x{}, y{};
			cin >> x >> y;
			sum += x * y;
			for (int i = 1; y >= i; i *= 2) {
				A.push_back(i * x);
				y -= i;
			}
			if (y) {
				A.push_back(y * x);
			}
		}
		if (sum % 2) {
			cout << "0\n";
			continue;
		}
		bitset<50001> dp;
		dp[0] = true;
		for (int x : A) {
			dp |= (dp << x);
		}
		cout << dp[sum / 2] << "\n";
	}
	return 0;
}
