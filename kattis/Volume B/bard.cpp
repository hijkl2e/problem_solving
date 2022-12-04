#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, E{};
	cin >> N >> E;
	vector<int> A(N + 1);
	while (E--) {
		int K{};
		cin >> K;
		vector<int> B(K);
		for (int i = 0; i < K; ++i) {
			cin >> B[i];
		}
		int x{};
		if (count(B.begin(), B.end(), 1)) {
			x = A[1] + 1;
		} else {
			for (int y : B) {
				x |= A[y];
			}
		}
		for (int y : B) {
			A[y] |= x;
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (A[i] == A[1]) {
			cout << i << "\n";
		}
	}
	return 0;
}
