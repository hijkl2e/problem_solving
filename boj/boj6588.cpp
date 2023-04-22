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
	vector<int> P;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			P.push_back(i);
		}
	}
	vector<int> A(1000001, -1);
	for (int i = 1; i < 99; ++i) {
		for (int j = i; j < P.size() && P[i] + P[j] < A.size(); ++j) {
			int x = P[i] + P[j];
			if (A[x] == -1) {
				A[x] = P[i];
			}
		}
	}
	int N{};
	while (cin >> N, N) {
		cout << N << " = " << A[N] << " + " << N - A[N] << "\n";
	}
	return 0;
}
