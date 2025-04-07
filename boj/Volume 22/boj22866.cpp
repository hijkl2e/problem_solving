#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N);
	vector<int> C(N, -1);
	stack<int> st;
	for (int i = 0; i < N; ++i) {
		while (st.size() && A[i] >= A[st.top()]) {
			st.pop();
		}
		B[i] = st.size();
		if (st.size()) {
			C[i] = st.top();
		}
		st.push(i);
	}
	while (st.size()) {
		st.pop();
	}
	for (int i = N - 1; i >= 0; --i) {
		while (st.size() && A[i] >= A[st.top()]) {
			st.pop();
		}
		B[i] += st.size();
		if (st.size() && (C[i] == -1 || i - C[i] > st.top() - i)) {
			C[i] = st.top();
		}
		st.push(i);
	}
	for (int i = 0; i < N; ++i) {
		if (B[i]) {
			cout << B[i] << " " << C[i] + 1 << "\n";
		} else {
			cout << "0\n";
		}
	}
	return 0;
}
