#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		int x{}, y{}, z{};
		for (int i = 0; i < N; ++i) {
			cin >> x;
			if (x > 0) {
				++y;
			} else {
				++z;
			}
		}
		vector<int> A(N);
		vector<int> B(N);
		for (int i = 0; i < N; ++i) {
			A[i] = i < y ? (i + 1) : (2 * y - i - 1);
		}
		for (int i = 0; i < N; ++i) {
			B[i] = i < 2 * z ? (i % 2 ^ 1) : (i - 2 * z + 1);
		}
		for (int i = 0; i < N; ++i) {
			cout << A[i] << (i == N - 1 ? "\n" : " ");
		}
		for (int i = 0; i < N; ++i) {
			cout << B[i] << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
