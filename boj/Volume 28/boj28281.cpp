#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, X{};
	cin >> N >> X;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans = 1e9;
	for (int i = 0; i < N - 1; ++i) {
		ans = min(ans, A[i] + A[i + 1]);
	}
	ans *= X;
	cout << ans << "\n";
	return 0;
}
