#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{}, T{}, N{};
	cin >> L >> T >> N;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		char c{};
		cin >> A[i].first >> c;
		A[i].second = c == 'L' ? -1 : 1;
	}
	T %= 2 * L;
	for (auto &[u, v] : A) {
		int t = T;
		while (t) {
			int d = min(v == 1 ? L - u : u, t);
			u += v * d;
			t -= d;
			v *= -1;
		}
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < N; ++i) {
		cout << A[i].first << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
