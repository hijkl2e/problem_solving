#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	deque<bool> B(N + 1);
	for (int i = 0; i < 4; ++i) {
		int x{};
		for (int j = 0; j < N; ++j) {
			if (B[A[j]] || x > A[j]) {
				continue;
			}
			B[A[j]] = true;
			x = A[j];
		}
	}
	bool yes = count(B.begin(), B.end(), true) == N;
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
