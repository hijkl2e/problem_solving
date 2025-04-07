#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, K{};
		cin >> N >> K;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		deque<bool> B(N + 1);
		for (int i = 0; i < N; ++i) {
			B[A[i]] = true;
		}
		int p{};
		while (B[p]) {
			++p;
		}
		A.push_back(p);
		K %= N + 1;
		rotate(A.begin(), A.end() - K, A.end());
		for (int i = 0; i < N; ++i) {
			cout << A[i] << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
