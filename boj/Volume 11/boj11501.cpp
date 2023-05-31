#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		vector<int> B(N);
		B[N - 1] = A[N - 1];
		for (int i = N - 2; i >= 0; --i) {
			B[i] = max(B[i + 1], A[i]);
		}
		ll ans = accumulate(B.begin(), B.end(), 0LL) - accumulate(A.begin(), A.end(), 0LL);
		cout << ans << "\n";
	}
	return 0;
}
