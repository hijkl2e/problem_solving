#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(M);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	vector<int> C;
	for (int i = 0; i < N; ++i) {
		if (!binary_search(B.begin(), B.end(), A[i])) {
			C.push_back(A[i]);
		}
	}
	cout << C.size() << "\n";
	if (C.size()) {
		for (int i = 0; i < C.size(); ++i) {
			cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
