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
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<int> psum(N + 1);
	partial_sum(A.begin(), A.end(), psum.begin());
	deque<bool> p = sieve();
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 2; i + j <= N; ++j) {
			if (p[j] && p[psum[i + j] - psum[i]]) {
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
