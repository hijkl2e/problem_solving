#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	deque<bool> A(N + 1);
	while (Q--) {
		int a{}, b{};
		cin >> a >> b;
		for (int i = a; i <= N; i += b) {
			A[i] = true;
		}
	}
	int ans = N - accumulate(A.begin(), A.end(), 0);
	cout << ans << "\n";
	return 0;
}
