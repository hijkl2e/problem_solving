#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int N{}, L{};
		cin >> N >> L;
		vector<int> A(N);
		vector<ii> B(N);
		int R{};
		for (int i = 0; i < N; ++i) {
			cin >> B[i].first >> B[i].second;
			R += B[i].second;
			B[i].second = (B[i].second ? 1 : -1) * (i + 1);
		}
		sort(B.begin(), B.end());
		for (int i = 0; i < N; ++i) {
			A[i] = B[i].first;
		}
		for (int i = 0, l = 0, r = N - R; i < N; ++i) {
			if (B[i].second > 0) {
				B[r++].first = L - A[i];
			} else {
				B[l++].first = A[i];
			}
		}
		for (int i = 0; i < N; ++i) {
			B[i].second = abs(B[i].second);
		}
		sort(B.begin(), B.end());
		cout << "Case #" << tc << ": ";
		for (int i = 0; i < N; ++i) {
			cout << B[i].second << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
