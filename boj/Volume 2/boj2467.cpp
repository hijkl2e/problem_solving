#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ii ans{A[0], A[N - 1]};
	int S = abs(A[0] + A[N - 1]);
	int p1 = 0, p2 = N - 1;
	while (p1 < p2) {
		int X = A[p1] + A[p2];
		if (S > abs(X)) {
			ans = {A[p1], A[p2]};
			S = abs(X);
		}
		if (X < 0) {
			++p1;
		} else {
			--p2;
		}
	}
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}
