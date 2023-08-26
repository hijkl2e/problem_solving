#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(6);
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		++A[(y - 1) / 2 * 2 + x];
	}
	A[1] += A[0];
	int ans{};
	for (int i = 1; i < 6; ++i) {
		if (A[i]) {
			ans += (A[i] - 1) / K + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
