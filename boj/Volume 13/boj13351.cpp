#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, S{};
	cin >> M >> S;
	vector<vector<int>> A(M, vector<int>(S));
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < S; ++j) {
			cin >> A[i][j];
		}
	}
	int cnt{};
	deque<bool> B(S + 1);
	for (int i = 0; i < S; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!B[A[j][i]]) {
				B[A[j][i]] = true;
				++cnt;
			}
		}
		if (i + 1 == cnt) {
			break;
		}
	}
	vector<int> C;
	C.reserve(cnt);
	for (int i = 1; i <= S; ++i) {
		if (B[i]) {
			C.push_back(i);
		}
	}
	cout << C.size() << "\n";
	for (int i = 0; i < C.size(); ++i) {
		cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
	}
	return 0;
}
