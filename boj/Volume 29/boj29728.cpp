#include <bits/stdc++.h>

using namespace std;

deque<bool> sieve() {
	deque<bool> p(5000001, true);
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
	cin >> N;
	int b{}, s{};
	for (int i = 1; i <= N; ++i) {
		if (p[i]) {
			s = s + min(b, 1) + 1;
			b = max(b - 1, 0);
		} else {
			++b;
		}
	}
	cout << b << " " << s << "\n";
	return 0;
}
