#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	deque<bool> A(N);
	int cnt{};
	for (int i = 0; i < N; i += (i % 10 == 6 ? 4 : 3)) {
		A[i] = true;
		++cnt;
	}
	while (Q--) {
		int x{};
		cin >> x;
		--x;
		cnt += A[x] ? -1 : 1;
		A[x] ^= true;
		cout << cnt << "\n";
	}
	return 0;
}
