#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{};
	cin >> N >> L;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first;
		A[i].second = (A[i].first < 0 ? -1 : 1) * (i + 1);
		A[i].first = abs(A[i].first);
	}
	sort(A.begin(), A.end());
	int l = -1, r = -1, x = N - 1;
	for (int i = 0; i < N; ++i) {
		if (A[i].second > 0) {
			if (r == -1) {
				r = L - A[i].first;
			}
			--x;
		} else {
			l = A[i].first;
		}
	}
	cout << abs(A[x + (l < r)].second) << " " << max(l, r) << "\n";
	return 0;
}
