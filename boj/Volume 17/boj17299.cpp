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
	vector<int> B(1000001);
	for (int i = 0; i < N; ++i) {
		++B[A[i]];
	}
	vector<int> C(N, -1);
	stack<int> st;
	for (int i = 0; i < N; ++i) {
		while (st.size() && B[A[st.top()]] < B[A[i]]) {
			C[st.top()] = A[i];
			st.pop();
		}
		st.push(i);
	}
	for (int i = 0; i < N; ++i) {
		cout << C[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
