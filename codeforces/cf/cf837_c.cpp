#include <bits/stdc++.h>

using namespace std;

deque<bool> sieve() {
	deque<bool> p(31623, true);
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
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		map<int, int> freq;
		for (int x : A) {
			for (int y : P) {
				if (x % y == 0) {
					while (x % y == 0) {
						x /= y;
					}
					++freq[y];
				}
			}
			if (x > 1) {
				++freq[x];
			}
		}
		bool yes{};
		for (auto &p : freq) {
			if (p.second > 1) {
				yes = true;
				break;
			}
		}
		cout << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}
