#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<map<int, int>> A(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			int x{};
			cin >> x;
			int p = 1;
			while (A[i][p]) {
				p = 2 * p + (x > A[i][p]);
			}
			A[i][p] = x;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (auto &p : A[i]) {
			p.second = 0;
		}
	}
	sort(A.begin(), A.end());
	A.resize(unique(A.begin(), A.end()) - A.begin());
	cout << A.size() << "\n";
	return 0;
}
