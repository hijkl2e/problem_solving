#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

deque<bool> sieve() {
	deque<bool> p(1001, true);
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
	vector<iii> A(1001);
	for (int i = 0; i < P.size(); ++i) {
		for (int j = i; j < P.size(); ++j) {
			for (int k = j; k < P.size(); ++k) {
				int sum = P[i] + P[j] + P[k];
				if (sum < A.size() && get<0>(A[sum]) == 0) {
					A[sum] = {P[i], P[j], P[k]};
				}
			}
		}
	}
	int T{};
	cin >> T;
	while (T--) {
		int K{};
		cin >> K;
		auto &[a, b, c] = A[K];
		cout << a << " " << b << " " << c << "\n";
	}
	return 0;
}
