#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(1 << (K + 1));
	vector<vector<int>> B(N);
	for (int i = 0; i < N; ++i) {
		fill(A.begin(), A.end(), 0);
		for (int j = 0; j < K; ++j) {
			int x{};
			cin >> x;
			int p = 1;
			while (A[p]) {
				p = 2 * p + (A[p] < x);
			}
			A[p] = x;
			B[i].push_back(p);
		}
		sort(B[i].begin(), B[i].end());
	}
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	cout << B.size() << "\n";
	return 0;
}
