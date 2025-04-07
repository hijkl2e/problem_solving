#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int A[10][10];
int B[6];
int ans;

void solve(int n, int cnt) {
	if (n == 100) {
		ans = min(ans, cnt);
		return;
	}
	int x = n / 10, y = n % 10;
	if (A[x][y] == 0) {
		return solve(n + 1, cnt);
	}
	for (int l = 1; l < 6 && x + l < 11 && y + l < 11; ++l) {
		if (B[l] == 0) {
			continue;
		}
		bool flag{};
		for (int i = 0; i < l; ++i) {
			for (int j = 0; j < l; ++j) {
				if (A[x + i][y + j] == 0) {
					flag = true;
				}
			}
		}
		if (flag) {
			break;
		}
		for (int k = 0; k < 2; ++k) {
			for (int i = 0; i < l; ++i) {
				for (int j = 0; j < l; ++j) {
					A[x + i][y + j] = k;
				}
			}
			if (k == 0) {
				--B[l];
				solve(n + 1, cnt + 1);
				++B[l];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = 1; i < 6; ++i) {
		B[i] = 5;
	}
	ans = INF;
	solve(0, 0);
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
