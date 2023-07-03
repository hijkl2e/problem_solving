#include <bits/stdc++.h>

using namespace std;

int solve(int x, int y) {
	int ret{};
	int z = x * y;
	while (z) {
		ret += z % 10;
		z /= 10;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(1001);
	for (int i = 0; i < N; ++i) {
		++B[A[i]];
	}
	int ans{};
	for (int i = 1; i < B.size(); ++i) {
		if (B[i] == 0) {
			continue;
		} else if (B[i] > 1) {
			ans = max(ans, solve(i, i));
		}
		for (int j = i + 1; j < B.size(); ++j) {
			if (B[j]) {
				ans = max(ans, solve(i, j));
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
