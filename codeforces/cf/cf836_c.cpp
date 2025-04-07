#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, x{};
		cin >> N >> x;
		if (N % x) {
			cout << "-1\n";
			continue;
		}
		vector<int> A(N + 1);
		for (int i = 1; i <= N; ++i) {
			A[i] = i;
		}
		A[N] = 1;
		A[1] = x;
		for (int i = x; i < N;) {
			for (int j = 2 * i; j < N; j += i) {
				if (N % j == 0) {
					A[i] = j;
					break;
				}
			}
			if (A[i] == i) {
				A[i] = N;
				break;
			}
			i = A[i];
		}
		for (int i = 1; i <= N; ++i) {
			cout << A[i] << (i == N ? "\n" : " ");
		}
	}
	return 0;
}
