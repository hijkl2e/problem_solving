#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	A[N - 1] = 1;
	for (int i = N - 2; i >= 0; --i) {
		A[i] = min(A[i], A[i + 1] + 1);
	}
	ll ans = accumulate(A.begin(), A.end(), 0LL);
	cout << ans << "\n";
	return 0;
}
