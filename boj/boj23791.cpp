#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(2 * N + 1);
	for (int i = 1; i < A.size(); ++i) {
		cin >> A[i].first;
		A[i].second = i - 1;
	}
	sort(A.begin(), A.end());
	vector<ii> B(2 * N + 1);
	for (int i = 1; i < B.size(); ++i) {
		B[i] = B[i - 1];
		if (A[i].second < N) {
			++B[i].first;
		} else {
			++B[i].second;
		}
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		int lo = 0, hi = 2 * N;
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			auto &[x, y] = B[mid];
			if (min(x, a) + min(y, b) < c) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		int ans = A[hi].second;
		cout << ans / N + 1 << " " << ans % N + 1 << "\n";
	}
	return 0;
}
