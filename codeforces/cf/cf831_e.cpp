#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> P(N + 1);
	for (int i = 2; i <= N; ++i) {
		cin >> P[i];
	}
	vector<int> dp1(N + 1, 1);
	vector<int> dp2(N + 1);
	for (int i = N; i > 0; --i) {
		dp1[P[i]] = max(dp1[P[i]], dp1[i] + 1);
		dp2[P[i]] += max(dp1[i], dp2[i]);
	}
	cout << dp2[0] << "\n";
	return 0;
}
