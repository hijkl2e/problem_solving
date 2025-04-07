#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, X{}, Y{};
	cin >> N >> M >> X >> Y;
	vector<ii> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	vector<int> B(9);
	for (int i = 0; i < 9; ++i) {
		B[i] = i + 1;
	}
	deque<bool> C(10);
	int cnt{};
	do {
		fill(C.begin(), C.end(), false);
		for (int i = 0; i < N; ++i) {
			C[B[i]] = true;
		}
		bool yes = true;
		for (auto &[a, b] : A) {
			if (a) {
				yes &= B[a - 1] == b;
			} else {
				yes &= C[b];
			}
		}
		if (yes) {
			++cnt;
		}
		reverse(B.begin() + N, B.end());
	} while (next_permutation(B.begin(), B.end()));
	int ans = cnt * X + (cnt - 1) / 3 * Y;
	cout << ans << "\n";
	return 0;
}
