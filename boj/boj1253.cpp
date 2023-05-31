#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &A, int p) {
	int s = 0, e = A.size() - 1;
	while (s < e) {
		if (s == p) {
			++s;
			continue;
		} else if (e == p) {
			--e;
			continue;
		}
		int sum = A[s] + A[e];
		if (sum < A[p]) {
			++s;
		} else if (sum > A[p]) {
			--e;
		} else {
			return true;
		}
	}
	return false;
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
	sort(A.begin(), A.end());
	int ans{};
	for (int i = 0; i < N; ++i) {
		if (solve(A, i)) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
