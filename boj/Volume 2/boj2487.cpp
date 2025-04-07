#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	deque<bool> B(N + 1);
	int ans = 1;
	for (int i = 1; i <= N; ++i) {
		if (B[i]) {
			continue;
		}
		int cnt{}, j = i;
		while (!B[j]) {
			B[j] = true;
			j = A[j];
			++cnt;
		}
		ans = lcm(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
