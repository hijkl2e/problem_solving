#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, K{};
		cin >> N >> K;
		vector<ii> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i].first;
			A[i].second = i;
		}
		sort(A.begin(), A.end());
		vector<int> B(K + 1);
		deque<bool> C(N);
		int s = 0, e = N - 1;
		for (auto &[u, v] : A) {
			while (C[s]) {
				++s;
			}
			while (C[e]) {
				--e;
			}
			B[u] = max(B[u], 2 * (e - s + 1));
			C[v] = true;
		}
		for (int i = 1; i <= K; ++i) {
			cout << B[i] << (i == K ? "\n" : " ");
		}
	}
	return 0;
}
