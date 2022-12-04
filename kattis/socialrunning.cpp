#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans = 1e9;
	for (int i = 0; i < N; ++i) {
		ans = min(ans, A[i] + A[(i + 2) % N]);
	}
	cout << ans << "\n";
	return 0;
}
