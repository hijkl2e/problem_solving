#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	string s;
	for (int tc = 0; cin >> N >> M >> s, N; ++tc) {
		char c = s[1];
		cin.ignore();
		vector<string> A(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, A[i]);
		}
		getline(cin, s);
		vector<string> B(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, B[i]);
		}
		vector<string> C(A.begin(), A.end());
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (C[i][j] == c) {
					C[i][j] = B[i][j];
				}
			}
		}
		ii idx1{-1, -1}, idx2{-1, -1};
		for (int i = 0; i < N; ++i) {
			if (idx1.first == -1 && A[i].find(c) != -1) {
				idx1 = {i, A[i].find(c)};
			}
			if (idx2.first == -1 && B[i].find(c) != -1) {
				idx2 = {i, B[i].find(c)};
			}
		}
		int dx = idx2.first - idx1.first;
		int dy = idx2.second - idx1.second;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (B[i][j] != c) {
					continue;
				}
				int nx = i + dx;
				int ny = j + dy;
				if (0 <= nx && nx < N && 0 <= ny && ny < M) {
					C[nx][ny] = c;
				}
			}
		}
		if (tc) {
			cout << "\n";
		}
		for (int i = 0; i < N; ++i) {
			cout << C[i] << "\n";
		}
	}
	return 0;
}
