#include <bits/stdc++.h>

using namespace std;

deque<bool> sieve() {
	deque<bool> p(246913, true);
	p[0] = p[1] = false;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			for (int j = 2 * i; j < p.size(); j += i) {
				p[j] = false;
			}
		}
	}
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	deque<bool> p = sieve();
	int N{};
	while (cin >> N, N) {
		int ans{};
		for (int i = N + 1; i <= 2 * N; ++i) {
			if (p[i]) {
				++ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
