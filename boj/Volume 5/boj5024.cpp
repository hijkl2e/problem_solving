#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, P{};
	cin >> N >> P;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int ans = 1e9;
	for (int i = 0; i < N; ++i) {
		ans = min(ans, A[i] - P * (i + 1));
	}
	ans = A[0] - ans;
	cout << ans << "\n";
	return 0;
}
