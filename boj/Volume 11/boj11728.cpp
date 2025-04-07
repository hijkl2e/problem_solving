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
	vector<int> C;
	merge(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));
	for (int i = 0; i < C.size(); ++i) {
		cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
	}
	return 0;
}
