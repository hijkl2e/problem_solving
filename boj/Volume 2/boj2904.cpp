#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	map<int, int> B;
	for (int i = 0; i < N; ++i) {
		int x = A[i];
		for (int j = 2; j * j <= x; ++j) {
			while (x % j == 0) {
				x /= j;
				++B[j];
			}
		}
		if (x > 1) {
			++B[x];
		}
	}
	int ans_x = 1, ans_y{};
	for (auto &[u, v] : B) {
		int k = v / N;
		if (k == 0) {
			continue;
		}
		for (int i = 0; i < k; ++i) {
			ans_x *= u;
		}
		for (int i = 0; i < N; ++i) {
			int x = A[i], cnt{};
			while (x % u == 0) {
				x /= u, ++cnt;
			}
			ans_y += max(k - cnt, 0);
		}
	}
	cout << ans_x << " " << ans_y << "\n";
	return 0;
}
