#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	ll ans = A[0];
	for (int i = 1; i < N; ++i) {
		if (A[i - 1] + 1 < A[i]) {
			ans += A[i];
		}
	}
	cout << ans << "\n";
	return 0;
}
