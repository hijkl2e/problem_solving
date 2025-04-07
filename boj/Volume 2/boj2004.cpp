#include <bits/stdc++.h>

using namespace std;

int solve(int x, int y) {
	int ret{};
	int z = 1;
	for (int i = 0; i < (y == 2 ? 30 : 13); ++i) {
		z *= y;
		ret += x / z;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	int t = solve(N, 2) - solve(N - M, 2) - solve(M, 2);
	int f = solve(N, 5) - solve(N - M, 5) - solve(M, 5);
	cout << min(t, f) << "\n";
	return 0;
}
