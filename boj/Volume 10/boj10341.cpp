#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string A, B;
	while (cin >> A >> B, stoi(A)) {
		int R = 5 + 4 * B.size();
		int C = 5 + 4 * A.size();
		vector<string> G(R, string(C, ' '));
		for (int i = 0; i < C; ++i) {
			G[0][i] = G[R - 1][i] = i == 0 || i == C - 1 ? '+' : '-';
		}
		for (int i = 1; i < R - 1; ++i) {
			G[i][0] = G[i][C - 1] = '|';
		}
		for (int i = 2; i < R - 2; ++i) {
			if (i % 4 == 2) {
				for (int j = 2; j < C - 2; ++j) {
					G[i][j] = j % 4 == 2 ? '+' : '-';
				}
			} else {
				for (int j = 2; j < C - 2; j += 4) {
					G[i][j] = '|';
				}
				for (int j = 5 - (i - 3) % 4; j < C - 2; j += 4) {
					G[i][j] = '/';
				}
			}
		}
		for (int i = 0; i < A.size(); ++i) {
			G[1][4 * (i + 1)] = A[i];
		}
		for (int i = 0; i < B.size(); ++i) {
			G[4 * (i + 1)][C - 2] = B[i];
		}
		for (int i = 0; i < B.size(); ++i) {
			for (int j = 0; j < A.size(); ++j) {
				int x = (A[j] - '0') * (B[i] - '0');
				G[4 * i + 3][4 * j + 3] = x / 10 + '0';
				G[4 * i + 5][4 * j + 5] = x % 10 + '0';
			}
		}
		string res = to_string(stoi(A) * stoi(B));
		for (int i = 0; i < A.size() && i < res.size(); ++i) {
			G[R - 2][4 * (A.size() - i) + 1] = i ? '/' : ' ';
			G[R - 2][4 * (A.size() - i) - 1] = res[res.size() - i - 1];
		}
		for (int i = A.size(); i < res.size(); ++i) {
			G[R - 2 - 4 * (i - A.size())][1] = '/';
			G[R - 4 * (i - A.size() + 1)][1] = res[res.size() - i - 1];
		}
		for (auto &s : G) {
			cout << s << "\n";
		}
	}
	return 0;
}
