#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> B(N + 1, vector<int>(M + 1));
	vector<vector<int>> C(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			B[i][j] = (A[i - 1][j - 1] == 'J') + B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
			C[i][j] = (A[i - 1][j - 1] == 'O') + C[i - 1][j] + C[i][j - 1] - C[i - 1][j - 1];
		}
	}
	while (K--) {
		int a{}, b{}, c{}, d{};
		cin >> a >> b >> c >> d;
		int j = B[c][d] - B[a - 1][d] - B[c][b - 1] + B[a - 1][b - 1];
		int o = C[c][d] - C[a - 1][d] - C[c][b - 1] + C[a - 1][b - 1];
		int i = (c - a + 1) * (d - b + 1) - j - o;
		cout << j << " " << o << " " << i << "\n";
	}
	return 0;
}
