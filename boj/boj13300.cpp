#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(12);
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		++A[6 * x + y - 1];
	}
	int ans{};
	for (int i = 0; i < 12; ++i) {
		if (A[i]) {
			ans += (A[i] - 1) / K + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
