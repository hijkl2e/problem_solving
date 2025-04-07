#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	vector<int> B(K);
	for (int i = 0; i < N; ++i) {
		++B[A[i] % K];
	}
	int ans = *max_element(B.begin(), B.end());
	cout << ans << "\n";
	return 0;
}
