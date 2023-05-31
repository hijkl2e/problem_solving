#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, L{}, K{};
		cin >> N >> L >> K;
		vector<int> A(N);
		vector<ii> B(N);
		int R{};
		for (int i = 0; i < N; ++i) {
			cin >> A[i] >> B[i].second;
			if (B[i].second > 0) {
				++R;
			}
		}
		for (int i = 0, l = 0, r = N - R; i < N; ++i) {
			if (B[i].second > 0) {
				B[r++].first = L - A[i];
			} else {
				B[l++].first = A[i];
			}
		}
		sort(B.begin(), B.end());
		cout << B[K - 1].second << "\n";
	}
	return 0;
}
