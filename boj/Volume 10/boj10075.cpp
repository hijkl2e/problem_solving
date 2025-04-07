#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		cin >> C[i];
	}
	vector<int> H(N);
	vector<int> P(N);
	for (int i = 1; i < N; ++i) {
		cin >> H[i] >> P[i];
	}
	int ans{};
	for (int i = N - 1; i > 0; --i) {
		if (P[i] == 0) {
			C[H[i]] = max(C[H[i]] - C[i], 0);
			ans += C[i];
		} else if (P[i] == 1) {
			C[H[i]] += C[i];
		} else {
			C[H[i]] = max(C[H[i]], C[i]);
		}
	}
	ans += C[0];
	cout << ans << "\n";
	return 0;
}
