#include <bits/stdc++.h>

using namespace std;

bool solve(int x) {
	static deque<bool> A(10);
	fill(A.begin(), A.end(), false);
	while (x) {
		int r = x % 10;
		if (A[r]) {
			return false;
		}
		A[r] = true;
		x /= 10;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	while (cin >> N >> M) {
		int ans{};
		for (int i = N; i <= M; ++i) {
			if (solve(i)) {
				++ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
