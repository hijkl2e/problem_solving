#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> C(N);
		for (int i = 0; i < N; ++i) {
			cin >> C[i];
		}
		int K{};
		cin >> K;
		stack<int> st;
		for (int i = 0; i < N; ++i) {
			while (st.size() && C[st.top()] >= C[i]) {
				st.pop();
			}
			st.push(i);
		}
		vector<int> B;
		while (st.size()) {
			B.push_back(st.top());
			st.pop();
		}
		reverse(B.begin(), B.end());
		vector<int> A(N);
		A[B[0]] += K / C[B[0]];
		K %= C[B[0]];
		for (int i = 1; i < B.size(); ++i) {
			int x = C[B[i - 1]];
			int y = min(K / (C[B[i]] - x), A[B[i - 1]]);
			A[B[i]] += y;
			A[B[i - 1]] -= y;
			K -= y * (C[B[i]] - x);
		}
		partial_sum(A.rbegin(), A.rend(), A.rbegin());
		for (int i = 0; i < N; ++i) {
			cout << A[i] << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
