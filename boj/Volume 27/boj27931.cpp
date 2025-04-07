#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9 + 11;

int solve(vector<int> &A, bool f) {
	if (A.size() < 2) {
		return INF;
	}
	int ret = INF;
	for (int i = 0; i < A.size() - 1; ++i) {
		if (f || (A[i + 1] - A[i]) % 2) {
			ret = min(ret, A[i + 1] - A[i]);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A, B, C;
	while (N--) {
		int x{};
		cin >> x;
		if (x % 2) {
			A.push_back(x);
		} else {
			B.push_back(x);
		}
		C.push_back(x);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());
	int ans_x = min(solve(A, true), solve(B, true));
	int ans_y = solve(C, false);
	cout << (ans_x == INF ? -1 : ans_x) << " " << (ans_y == INF ? -1 : ans_y) << "\n";
	return 0;
}
