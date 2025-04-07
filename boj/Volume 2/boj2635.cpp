#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int maxv{}, X{};
	for (int i = 1; i <= N; ++i) {
		int x = N, y = i;
		int cnt = 2;
		while (x - y >= 0) {
			int z = x - y;
			x = y, y = z;
			++cnt;
		}
		if (maxv < cnt) {
			maxv = cnt;
			X = i;
		}
	}
	vector<int> A(maxv);
	A[0] = N, A[1] = X;
	for (int i = 2; i < A.size(); ++i) {
		A[i] = A[i - 2] - A[i - 1];
	}
	cout << maxv << "\n";
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
	}
	return 0;
}
