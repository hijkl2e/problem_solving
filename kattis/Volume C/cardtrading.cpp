#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{}, K{};
	cin >> N >> T >> K;
	vector<int> C(T);
	while (N--) {
		int x{};
		cin >> x;
		++C[x - 1];
	}
	vector<int> A(T);
	vector<int> B(T);
	for (int i = 0; i < T; ++i) {
		cin >> A[i] >> B[i];
	}
	vector<ll> D(T);
	ll ans{};
	for (int i = 0; i < T; ++i) {
		ans += C[i] * B[i];
		D[i] = C[i] * B[i] + (2 - C[i]) * A[i];
	}
	sort(D.begin(), D.end());
	ans -= accumulate(D.begin(), D.begin() + K, 0LL);
	cout << ans << "\n";
	return 0;
}
