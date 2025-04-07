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
	sort(P.begin(), P.end());
	int ans{};
	for (int i = 0; i <= N / 2; ++i) {
		ans += P[i] / 2;
	}
	for (int i = N / 2 + 1; i < N; ++i) {
		ans += P[i];
	}
	cout << ans << "\n";
	return 0;
}
