#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int x{}, y{}, N{};
		cin >> x >> y >> N;
		if (y - x < N * (N - 1) / 2) {
			cout << "-1\n";
			continue;
		}
		vector<int> A(N);
		A[0] = y;
		A[N - 1] = x;
		for (int i = 1; i < N - 1; ++i) {
			A[i] = y - i * (i + 1) / 2;
		}
		reverse(A.begin(), A.end());
		for (int i = 0; i < N; ++i) {
			cout << A[i] << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
