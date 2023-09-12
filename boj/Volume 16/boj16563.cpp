#include <bits/stdc++.h>

using namespace std;

vector<int> sieve() {
	vector<int> p(5000001, -1);
	for (int i = 2; i < p.size(); ++i) {
		if (p[i] == -1) {
			for (int j = 2 * i; j < p.size(); j += i) {
				if (p[j] == -1) {
					p[j] = i;
				}
			}
		}
	}
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> p = sieve();
	int N{};
	cin >> N;
	vector<int> A;
	while (N--) {
		int x{};
		cin >> x;
		A.clear();
		while (p[x] != -1) {
			A.push_back(p[x]);
			x /= p[x];
		}
		A.push_back(x);
		for (int i = 0; i < A.size(); ++i) {
			cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
