#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{100, 50, 20, 10, 5, 2, 1};
	int N{};
	cin >> N;
	int M{};
	while (N--) {
		int x{};
		cin >> x;
		M = abs(M - x);
	}
	int ans{};
	for (int i = 0; i < 7; ++i) {
		ans += M / A[i];
		M %= A[i];
	}
	cout << ans << "\n";
	return 0;
}
