#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		vector<int> B(M);
		for (int i = 0; i < M; ++i) {
			cin >> B[i];
		}
		int x{}, y{}, k{};
		for (int i = 0; i < M; ++i) {
			k |= B[i];
		}
		for (int i = 0; i < N; ++i) {
			x ^= A[i];
			y ^= A[i] | k;
		}
		cout << min(x, y) << " " << max(x, y) << "\n";
	}
	return 0;
}
