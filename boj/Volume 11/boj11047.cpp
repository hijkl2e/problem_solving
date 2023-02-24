#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans{};
	for (int i = N - 1; i >= 0; --i) {
		ans += K / A[i];
		K %= A[i];
	}
	cout << ans << "\n";
	return 0;
}
