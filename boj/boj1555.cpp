#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x) {
	if (x < 2 || x > 24300019) {
		return false;
	}
	static deque<bool> p;
	if (p.empty()) {
		p.assign(54001, true);
		p[0] = p[1] = false;
		for (int i = 2; i < p.size(); ++i) {
			if (p[i]) {
				for (int j = 2 * i; j < p.size(); j += i) {
					p[j] = false;
				}
			}
		}
	}
	if (x < p.size()) {
		return p[x];
	}
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> B(1 << N);
	for (int i = 0; i < N; ++i) {
		B[1 << i].push_back(A[i]);
	}
	for (int i = 1; i < (1 << N); ++i) {
		if (__builtin_popcount(i) == 1) {
			continue;
		}
		for (int j = 1; j < (1 << N); ++j) {
			if ((i & j) != j || j > (i ^ j)) {
				continue;
			}
			int k = i ^ j;
			for (int x : B[j]) {
				for (int y : B[k]) {
					B[i].push_back(x + y);
					B[i].push_back(x - y);
					B[i].push_back(y - x);
					B[i].push_back(x * y);
					if (x > 0 && y > 0) {
						B[i].push_back(x / y);
						B[i].push_back(y / x);
					}
				}
			}
		}
		sort(B[i].begin(), B[i].end());
		B[i].resize(unique(B[i].begin(), B[i].end()) - B[i].begin());
	}
	int minv{}, maxv{};
	minv = maxv = -1;
	for (int x : B.back()) {
		if (is_prime(x)) {
			minv = minv == -1 ? x : minv;
			maxv = max(maxv, x);
		}
	}
	if (minv == -1) {
		cout << "-1\n";
	} else {
		cout << minv << "\n" << maxv << "\n";
	}
	return 0;
}
