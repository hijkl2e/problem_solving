#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

ll solve(vector<int> &A) {
	if (A.empty()) {
		return -INF;
	}
	vector<int> B;
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] >= 0) {
			B.push_back(A[i]);
		}
	}
	if (B.size()) {
		return accumulate(B.begin(), B.end(), 0LL);
	} else {
		return *max_element(A.begin(), A.end());
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A, B;
		for (int i = 0; i < N; ++i) {
			int x{};
			cin >> x;
			if (i % 2) {
				B.push_back(x);
			} else {
				A.push_back(x);
			}
		}
		ll ans = max(solve(A), solve(B));
		cout << ans << "\n";
	}
	return 0;
}
