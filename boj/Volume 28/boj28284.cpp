#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> S(M);
	vector<int> E(M);
	for (int i = 0; i < M; ++i) {
		cin >> S[i] >> E[i];
		++E[i];
	}
	vector<int> B(2 * M + 1);
	copy(S.begin(), S.end(), B.begin());
	copy(E.begin(), E.end(), B.begin() + M);
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	vector<int> C(B.size());
	for (int i = 0; i < M; ++i) {
		int p = lower_bound(B.begin(), B.end(), S[i]) - B.begin();
		++C[p];
		p = lower_bound(B.begin(), B.end(), E[i]) - B.begin();
		--C[p];
	}
	partial_sum(C.begin(), C.end(), C.begin());
	vector<int> D(M + 1);
	for (int i = 0; i < C.size() - 1; ++i) {
		D[C[i]] += B[i + 1] - B[i];
	}
	sort(A.begin(), A.end());
	vector<ll> R(A.begin(), A.end());
	reverse(R.begin(), R.end());
	partial_sum(A.begin(), A.end(), A.begin());
	partial_sum(R.begin(), R.end(), R.begin());
	ll ans_x{}, ans_y{};
	for (int i = 1; i <= M; ++i) {
		ans_x += D[i] * A[i - 1];
		ans_y += D[i] * R[i - 1];
	}
	cout << ans_x << " " << ans_y << "\n";
	return 0;
}
