#include <bits/stdc++.h>

using namespace std;

int N, T;
vector<int> A;

bool solve(int x) {
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		if (i < x) {
			B[i] = max(A[i], T);
			continue;
		}
		if (B[i - x] + 1 > A[i]) {
			return false;
		}
		B[i] = max(B[i - x] + T, A[i]);
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> T;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int lo = 0, hi = N;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (solve(mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << hi << "\n";
	return 0;
}
