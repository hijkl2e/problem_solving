#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int N{};
	cin >> N;
	cin.ignore();
	vector<vector<string>> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, S);
		istringstream iss(S);
		for (int j = 0; getline(iss, S, ','); ++j) {
			if (j) {
				S = S.substr(1);
			}
			A[i].push_back(S);
		}
	}
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == j) {
				continue;
			}
			int cnt{};
			for (int k = 0; k < A[i].size(); ++k) {
				if (A[i][k] != A[j][k]) {
					++cnt;
				}
			}
			B[i] = max(B[i], cnt);
		}
	}
	int minv = *min_element(B.begin(), B.end());
	for (int i = 0; i < N; ++i) {
		if (B[i] != minv) {
			continue;
		}
		for (int j = 0; j < A[i].size(); ++j) {
			cout << A[i][j] << (j == A[i].size() - 1 ? "\n" : ", ");
		}
	}
	return 0;
}
