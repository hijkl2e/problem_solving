#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	deque<bool> B(360);
	B[0] = true;
	for (int i = 0; i < N; ++i) {
		int x = A[i];
		while (x) {
			for (int j = 0; j < N; ++j) {
				if (B[j]) {
					B[(j + x) % 360] = true;
				}
			}
			x = (x + A[i]) % 360;
		}
	}
	while (K--) {
		int x{};
		cin >> x;
		cout << (B[x] ? "YES" : "NO") << "\n";
	}
	return 0;
}
