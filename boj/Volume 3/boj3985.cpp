#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{}, N{};
	cin >> L >> N;
	vector<int> A(L + 1);
	int maxv{}, ans_x{}, ans_y{};
	for (int i = 1; i <= N; ++i) {
		int l{}, r{};
		cin >> l >> r;
		if (maxv < r - l + 1) {
			maxv = r - l + 1;
			ans_x = i;
		}
		for (int j = l; j <= r; ++j) {
			if (A[j] == 0) {
				A[j] = i;
			}
		}
	}
	vector<int> B(N + 1);
	for (int i = 1; i <= L; ++i) {
		++B[A[i]];
	}
	maxv = 0;
	for (int i = 1; i <= N; ++i) {
		if (maxv < B[i]) {
			maxv = B[i];
			ans_y = i;
		}
	}
	cout << ans_x << "\n" << ans_y << "\n";
	return 0;
}
