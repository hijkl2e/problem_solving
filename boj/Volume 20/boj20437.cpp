#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		int K{};
		cin >> K;
		cin.ignore();
		vector<vector<int>> A(26);
		for (int i = 0; i < S.size(); ++i) {
			A[S[i] - 'a'].push_back(i);
		}
		int minv = INF, maxv = -INF;
		for (int i = 0; i < 26; ++i) {
			for (int j = K - 1; j < A[i].size(); ++j) {
				int len = A[i][j] - A[i][j - K + 1] + 1;
				minv = min(minv, len);
				maxv = max(maxv, len);
			}
		}
		if (minv == INF) {
			cout << "-1\n";
		} else {
			cout << minv << " " << maxv << "\n";
		}
	}
	return 0;
}
