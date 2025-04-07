#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> solve(const vector<ll> &A) {
	vector<ll> ret(1 << A.size());
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < A.size(); ++j) {
			if (i & (1 << j)) {
				ret[i] += A[j];
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<ll> B = solve(vector<ll>(A.begin(), A.begin() + N / 2));
	vector<ll> C = solve(vector<ll>(A.begin() + N / 2, A.end()));
	sort(C.begin(), C.end());
	int ans{};
	for (int i = 0; i < B.size(); ++i) {
		ans += upper_bound(C.begin(), C.end(), M - B[i]) - C.begin();
	}
	cout << ans << "\n";
	return 0;
}
