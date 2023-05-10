#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, P{};
	cin >> N >> P;
	if (P == 100) {
		cout << "impossible\n";
		return 0;
	}
	int sum{};
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		sum += x;
	}
	int ans = (P * N - sum - 1) / (100 - P) + 1;
	cout << ans << "\n";
	return 0;
}
