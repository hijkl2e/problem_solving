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
	int M{};
	cin >> M;
	vector<int> B(M);
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	vector<int> C;
	while (A.size() && B.size()) {
		auto it1 = max_element(A.begin(), A.end());
		auto it2 = max_element(B.begin(), B.end());
		if (*it1 > *it2) {
			A.erase(it1);
		} else if (*it1 < *it2) {
			B.erase(it2);
		} else {
			C.push_back(*it1);
			A.erase(A.begin(), it1 + 1);
			B.erase(B.begin(), it2 + 1);
		}
	}
	cout << C.size() << "\n";
	for (int i = 0; i < C.size(); ++i) {
		cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
	}
	return 0;
}
