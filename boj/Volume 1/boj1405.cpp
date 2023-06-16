#include <bits/stdc++.h>

using namespace std;

const int dx[4]{0, 0, 1, -1};
const int dy[4]{1, -1, 0, 0};

int N;
vector<double> A;
vector<deque<bool>> B;
double ans;

void solve(int n, int x, int y, double p) {
	if (n == N) {
		ans += p;
		return;
	}
	B[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (B[nx][ny]) {
			continue;
		}
		solve(n + 1, nx, ny, p * A[i]);
	}
	B[x][y] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.resize(4);
	for (int i = 0; i < 4; ++i) {
		cin >> A[i];
		A[i] /= 100;
	}
	B.assign(31, deque<bool>(31));
	solve(0, 15, 15, 1);
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
