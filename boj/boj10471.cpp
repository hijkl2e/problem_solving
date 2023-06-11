#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int W{}, P{};
	cin >> W >> P;
	vector<int> A(P + 2);
	for (int i = 1; i <= P; ++i) {
		cin >> A[i];
	}
	A[P + 1] = W;
	deque<bool> B(W + 1);
	for (int i = 0; i < A.size(); ++i) {
		for (int j = i + 1; j < A.size(); ++j) {
			B[A[j] - A[i]] = true;
		}
	}
	vector<int> C;
	for (int i = 1; i <= W; ++i) {
		if (B[i]) {
			C.push_back(i);
		}
	}
	for (int i = 0; i < C.size(); ++i) {
		cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
	}
	return 0;
}
