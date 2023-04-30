#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A;

int sum(int x1, int y1, int x2, int y2) {
	int ret{};
	for (int i = x1; i <= x2; ++i) {
		for (int j = y1; j <= y2; ++j) {
			ret += A[i][j];
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.assign(N + 2, vector<int>(N + 2));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> A[i][j];
		}
	}
	int x1 = N / 2, y1 = N / 2;
	int x2 = x1 + 1, y2 = y1 + 1;
	vector<int> B{
		sum(x1 - 1, y1, x1 - 1, y2), sum(x2 + 1, y1, x2 + 1, y2),
		sum(x1, y1 - 1, x2, y1 - 1), sum(x1, y2 + 1, x2, y2 + 1)
	};
	int ans{};
	string log;
	while (true) {
		int p = max_element(B.begin(), B.end()) - B.begin();
		if (B[p] <= 0) {
			break;
		}
		ans += B[p];
		log += "UDLR"[p];
		int &u = p == 0 ? x1 : p == 1 ? x2 : p == 2 ? y1 : y2;
		int v = p % 2 ? (++u + 1) : (--u - 1);
		if (p < 2) {
			B[p] = sum(v, y1, v, y2);
			B[2] += A[u][y1 - 1];
			B[3] += A[u][y2 + 1];
		} else {
			B[p] = sum(x1, v, x2, v);
			B[0] += A[x1 - 1][u];
			B[1] += A[x2 + 1][u];
		}
	}
	cout << ans << "\n" << log << "\n";
	return 0;
}
