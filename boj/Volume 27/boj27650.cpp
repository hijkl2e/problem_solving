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
	vector<int> P;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			P.push_back(i);
		}
	}
	int N{};
	cin >> N;
	int lo = -1, hi = upper_bound(P.begin(), P.end(), N) - P.begin() - 1;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		cout << "? " << P[mid] << endl;
		int x{};
		cin >> x;
		if (x) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << "! " << P[hi] << endl;
	return 0;
}
