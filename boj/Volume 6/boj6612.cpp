#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{}, N{};
	while (cin >> L >> N) {
		vector<ii> A(N);
		for (int i = 0; i < N; ++i) {
			char c{};
			cin >> A[i].first >> c;
			A[i].second = c == 'L' ? -1 : 1;
		}
		sort(A.begin(), A.end());
		int l = -1, r = -1, x = N - 1;
		for (int i = 0; i < N; ++i) {
			if (A[i].second == 1) {
				if (r == -1) {
					r = L - A[i].first;
				}
				--x;
			} else {
				l = A[i].first;
			}
		}
		cout << "The last ant will fall down in ";
		cout << max(l, r) << " seconds - started at ";
		if (l == r) {
			cout << A[x].first << " and " << A[x + 1].first << ".\n";
		} else {
			cout << A[x + (l < r)].first << ".\n";
		}
	}
	return 0;
}
