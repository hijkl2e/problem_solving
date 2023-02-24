#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(3 * N + 1);
	for (int i = 1; i < A.size(); ++i) {
		cin >> A[i].first;
		A[i].second = i - 1;
	}
	sort(A.begin(), A.end());
	vector<iii> B(3 * N + 1);
	for (int i = 1; i < B.size(); ++i) {
		B[i] = B[i - 1];
		auto &[a, b, c] = B[i];
		if (A[i].second < N) {
			++a;
		} else if (A[i].second < 2 * N) {
			++b;
		} else {
			++c;
		}
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		int a{}, b{}, c{}, d{};
		cin >> a >> b >> c >> d;
		int lo = 0, hi = 3 * N;
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			auto &[x, y, z] = B[mid];
			if (min(x, a) + min(y, b) + min(z, c) < d) {
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
