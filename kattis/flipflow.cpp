#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t{}, s{}, N{};
	cin >> t >> s >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	int ans{};
	for (int i = 1; i <= N; ++i) {
		ans = s - max(ans - A[i] + A[i - 1], 0);
	}
	ans = max(ans - t + A[N], 0);
	cout << ans << "\n";
	return 0;
}
