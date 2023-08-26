#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<string> A;

int solve(int x, int y, bool f) {
	int ret{};
	if (A[x][y] == 'G' || A[x][y] == 'P') {
		ret += (A[x][y] == 'G') - f;
		f ^= true;
	}
	if ((A[x][y] == 'G' || A[x][y] == 'D') && x + 1 < N
			&& (A[x + 1][y] == 'Z' || A[x + 1][y] == 'P')) {
		ret += solve(x + 1, y, f);
	} else if ((A[x][y] == 'Z' || A[x][y] == 'P') && y > 0
			&& (A[x][y - 1] == 'G' || A[x][y - 1] == 'D')) {
		ret += solve(x, y - 1, f);
	}
	A[x][y] = 'X';
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int k{};
	for (int i = 0; i < N; ++i) {
		for (int j = M - 1; j >= 0; --j) {
			if (A[i][j] == 'X') {
				continue;
			}
			k += solve(i, j, A[i][j] == 'G' || A[i][j] == 'D');
		}
	}
	cout << (k > 0 ? "Scallion" : "Aubergine") << "\n";
	return 0;
}
