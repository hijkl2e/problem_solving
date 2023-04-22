#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, N{};
	cin >> M >> N;
	vector<int> A(N + 2);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<int> L(N + 2);
	vector<int> R(N + 2);
	for (int i = 1; i <= N; ++i) {
		L[i] = max(L[i - 1], A[i - 1]);
	}
	for (int i = N; i > 0; --i) {
		R[i] = max(R[i + 1], A[i + 1]);
	}
	int ans{};
	for (int i = 1; i <= N; ++i) {
		ans += max(min(L[i], R[i]) - A[i], 0);
	}
	cout << ans << "\n";
	return 0;
}
