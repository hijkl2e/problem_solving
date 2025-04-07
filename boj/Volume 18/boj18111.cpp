#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, B{};
	cin >> N >> M >> B;
	vector<int> A(257);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int x{};
			cin >> x;
			++A[x];
		}
	}
	ii ans{1e9, -1};
	for (int i = 0; i < 257; ++i) {
		int T{}, cnt = B;
		for (int j = 0; j < 257; ++j) {
			T += (i < j ? 2 : 1) * A[j] * abs(j - i);
			cnt += A[j] * (j - i);
		}
		if (cnt >= 0 && ans.first >= T) {
			ans = {T, i};
		}
	}
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}
