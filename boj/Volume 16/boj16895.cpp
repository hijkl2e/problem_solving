#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> P(N);
	for (int i = 0; i < N; ++i) {
		cin >> P[i];
	}
	int x{};
	for (int i = 0; i < N; ++i) {
		x ^= P[i];
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		if ((P[i] ^ x) < P[i]) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
