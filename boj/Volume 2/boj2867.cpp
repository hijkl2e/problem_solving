#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> solve(vector<int> &A, bool f) {
	vector<int> ret(A.size());
	stack<int> st;
	for (int i = 0; i < A.size(); ++i) {
		while (st.size()) {
			int x = st.top();
			if (A[x] < A[i] || (A[x] == A[i] && f)) {
				ret[x] = i - 1;
				st.pop();
			} else {
				break;
			}
		}
		st.push(i);
	}
	while (st.size()) {
		int x = st.top(); st.pop();
		ret[x] = A.size() - 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(A.begin(), A.end());
	reverse(B.begin(), B.end());
	ll ans{};
	for (int k = 0; k < 2; ++k) {
		vector<int> R = solve(A, false);
		vector<int> L = solve(B, true);
		reverse(L.begin(), L.end());
		for (int i = 0; i < N; ++i) {
			L[i] = N - L[i] - 1;
		}
		for (int i = 0; i < N; ++i) {
			ans += (R[i] - i + 1LL) * (i - L[i] + 1LL) * A[i];
		}
		for (int i = 0; i < N; ++i) {
			A[i] *= -1;
			B[i] *= -1;
		}
	}
	cout << ans << "\n";
	return 0;
}
