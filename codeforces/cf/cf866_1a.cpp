#include <bits/stdc++.h>

using namespace std;

int mex(vector<int> A) {
	int ret{};
	sort(A.begin(), A.end());
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] == ret) {
			++ret;
		} else if (A[i] > ret) {
			return ret;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		int x = mex(A);
		if (x == N) {
			cout << "No\n";
			continue;
		}
		int l = find(A.begin(), A.end(), x + 1) - A.begin();
		int r = find(A.rbegin(), A.rend(), x + 1).base() - A.begin();
		if (l == N) {
			cout << "Yes\n";
			continue;
		}
		fill(A.begin() + l, A.begin() + r, x);
		int y = mex(A);
		cout << (x + 1 == y ? "Yes" : "No") << "\n";
	}
	return 0;
}
