#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;
double ans;

bool solve(int x, int y) {
	ans += y / 2 * pow(2, (1 - 2 * x) / 4.0);
	y -= min(y, A[x]);
	if (y == 0) {
		return true;
	} else if (x == N) {
		return false;
	} else {
		return solve(x + 1, 2 * y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.resize(N + 2);
	for (int i = 2; i <= N; ++i) {
		cin >> A[i];
	}
	if (solve(1, 1)) {
		cout << fixed << setprecision(10);
		cout << ans << "\n";
	} else {
		cout << "impossible\n";
	}
	return 0;
}
