#include <bits/stdc++.h>

using namespace std;

deque<bool> sieve() {
	deque<bool> p(1000001, true);
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
	int M{}, N{};
	cin >> M >> N;
	for (int i = M; i <= N; ++i) {
		if (p[i]) {
			cout << i << "\n";
		}
	}
	return 0;
}
