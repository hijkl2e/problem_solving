#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, S{}, K{};
	cin >> R >> S >> K;
	K -= 2;
	cin.ignore();
	vector<string> A(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> B(R, vector<int>(S));
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < S; ++j) {
			B[i][j] = (j ? B[i][j - 1] : 0) + (A[i][j] == '*');
		}
	}
	int x{}, y{}, maxv{};
	for (int j = K; j < S - 1; ++j) {
		int cnt{};
		for (int i = 0; i < R - 1; ++i) {
			cnt += B[i][j] - B[i][j - K];
			if (i >= K) {
				cnt -= B[i - K][j] - B[i - K][j - K];
				if (maxv < cnt) {
					maxv = cnt;
					x = i - K, y = j - K;
				}
			}
		}
	}
	A[x][y] = A[x][y + K + 1] = A[x + K + 1][y] = A[x + K + 1][y + K + 1] = '+';
	for (int i = 0; i < K; ++i) {
		A[x][y + i + 1] = A[x + K + 1][y + i + 1] = '-';
		A[x + i + 1][y] = A[x + i + 1][y + K + 1] = '|';
	}
	cout << maxv << "\n";
	for (int i = 0; i < R; ++i) {
		cout << A[i] << "\n";
	}
	return 0;
}
