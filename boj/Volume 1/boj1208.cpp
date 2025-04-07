#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int K = 4e6;

vector<ll> solve(const vector<int> &A) {
	vector<ll> ret(K + 1);
	for (int i = 0; i < (1 << A.size()); ++i) {
		int sum{};
		for (int j = 0; j < A.size(); ++j) {
			if (i & (1 << j)) {
				sum += A[j];
			}
		}
		++ret[sum + K / 2];
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, S{};
	cin >> N >> S;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	if (N == 1) {
		cout << (A[0] == S) << "\n";
		return 0;
	}
	vector<ll> B = solve(vector<int>(A.begin(), A.begin() + N / 2));
	vector<ll> C = solve(vector<int>(A.begin() + N / 2, A.end()));
	ll ans{};
	for (int i = 0; i < B.size(); ++i) {
		int j = K + S - i;
		if (0 <= j && j < C.size()) {
			ans += B[i] * C[j];
		}
	}
	if (S == 0) {
		--ans;
	}
	cout << ans << "\n";
	return 0;
}
