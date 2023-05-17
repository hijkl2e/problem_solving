#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	int ans_x{}, ans_y{};
	if (A[N - 1] % 3 == 0) {
		auto it = lower_bound(A.begin(), A.end(), A[N - 1] / 3);
		if (*it == A[N - 1] / 3) {
			ans_x = it - A.begin() + 1;
		}
		it = lower_bound(A.begin(), A.end(), A[N - 1] / 3 * 2);
		if (*it == A[N - 1] / 3 * 2) {
			ans_y = it - A.begin() + 1;
		}
	}
	if (ans_x && ans_y) {
		cout << ans_x << " " << ans_y << "\n";
	} else {
		cout << "-1\n";
	}
	return 0;
}
