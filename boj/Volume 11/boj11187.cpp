#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int l{}, d{}, N{};
	cin >> l >> d >> N;
	vector<int> A(N + 2);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	A[N] = 6 - d;
	A[N + 1] = l - 6 + d;
	sort(A.begin(), A.end());
	int ans{};
	for (int i = 0; i <= N; ++i) {
		ans += (A[i + 1] - A[i] - d) / d;
	}
	cout << ans << "\n";
	return 0;
}
