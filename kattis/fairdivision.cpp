#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int P{}, N{};
		cin >> P >> N;
		vector<ii> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i].first;
			A[i].second = -i;
		}
		sort(A.begin(), A.end());
		vector<int> B(N);
		for (int i = 0; i < N; ++i) {
			int &val = B[-A[i].second];
			val = min(A[i].first, P / (N - i));
			P -= val;
		}
		if (P) {
			cout << "IMPOSSIBLE\n";
		} else {
			for (int i = 0; i < N; ++i) {
				cout << B[i] << (i == N - 1 ? "\n" : " ");
			}
		}
	}
	return 0;
}
