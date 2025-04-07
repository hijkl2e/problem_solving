#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, S{}, R{};
	cin >> N >> S >> R;
	deque<bool> A(N + 2);
	deque<bool> B(N + 2);
	while (S--) {
		int x{};
		cin >> x;
		A[x] = true;
	}
	while (R--) {
		int x{};
		cin >> x;
		B[x] = true;
	}
	for (int i = 1; i <= N; ++i) {
		if (A[i] && B[i]) {
			A[i] = B[i] = false;
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j : {-1, 1}) {
			if (A[i + j] && B[i]) {
				A[i + j] = B[i] = false;
			}
		}
	}
	int ans = accumulate(A.begin(), A.end(), 0);
	cout << ans << "\n";
	return 0;
}
