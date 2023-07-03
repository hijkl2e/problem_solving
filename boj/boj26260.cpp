#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A, B;

void solve(int l, int r, int p) {
	if (l < r) {
		solve(l, p - 1, (l + p - 1) / 2);
		solve(p + 1, r, (r + p + 1) / 2);
	}
	B.push_back(A[p]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.resize(++N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	solve(1, N - 1, N / 2);
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}
