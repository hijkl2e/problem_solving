#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	vector<int> C(K + 1);
	for (int i = 0; i < N; ++i) {
		++C[B[i]];
	}
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ans += N - C[A[i]];
	}
	cout << ans << "\n";
	return 0;
}
