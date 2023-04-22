#include <bits/stdc++.h>

using namespace std;

vector<string> A;

int read(int x1, int y1, int x2, int y2) {
	int ret{};
	for (int i = x1; i <= x2; ++i) {
		for (int j = y1; j <= y2; ++j) {
			ret = 10 * ret + A[i][j] - '0';
		}
	}
	return ret;
}

int solve(int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2) {
		return 0;
	}
	int ret = read(x1, y1, x1, y2) + solve(x1 + 1, y1, x2, y2);
	ret = max(ret, read(x2, y1, x2, y2) + solve(x1, y1, x2 - 1, y2));
	ret = max(ret, read(x1, y1, x2, y1) + solve(x1, y1 + 1, x2, y2));
	ret = max(ret, read(x1, y2, x2, y2) + solve(x1, y1, x2, y2 - 1));
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	cout << solve(0, 0, N - 1, M - 1) << "\n";
	return 0;
}
