#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		int cnt = 1, maxv{};
		for (int i = 1; i < N; ++i) {
			if (A[i] == A[i - 1]) {
				++cnt;
			} else {
				maxv = max(maxv, cnt);
				cnt = 1;
			}
		}
		maxv = max(maxv, cnt);
		vector<vector<int>> B(maxv);
		for (int i = 0; i < N; ++i) {
			B[i % maxv].push_back(A[i]);
		}
		cout << maxv << "\n";
		for (auto &v : B) {
			for (int i = 0; i < v.size(); ++i) {
				cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
			}
		}
	}
	return 0;
}
