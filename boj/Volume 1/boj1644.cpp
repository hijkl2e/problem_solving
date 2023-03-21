#include <bits/stdc++.h>

using namespace std;

deque<bool> sieve() {
	deque<bool> p(4000001, true);
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
	vector<int> P;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			P.push_back(i);
		}
	}
	int N{};
	cin >> N;
	int p1{}, p2{}, sum{}, ans{};
	while (true) {
		if (sum < N) {
			if (p2 == P.size()) {
				break;
			}
			sum += P[p2++];
		} else {
			if (sum == N) {
				++ans;
			}
			sum -= P[p1++];
		}
	}
	cout << ans << "\n";
	return 0;
}
