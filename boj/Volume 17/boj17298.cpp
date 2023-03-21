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
	vector<int> B(N, -1);
	stack<int> st;
	for (int i = 0; i < N; ++i) {
		while (st.size() && A[st.top()] < A[i]) {
			B[st.top()] = A[i];
			st.pop();
		}
		st.push(i);
	}
	for (int i = 0; i < N; ++i) {
		cout << B[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
