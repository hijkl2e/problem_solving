#include <bits/stdc++.h>

using namespace std;

deque<bool> sieve() {
	deque<bool> p(10001, true);
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
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		for (int i = N / 2;; --i) {
			if (p[i] && p[N - i]) {
				cout << i << " " << N - i << "\n";
				break;
			}
		}
	}
	return 0;
}
