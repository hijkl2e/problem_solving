#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

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
		vector<int> B(201);
		for (int i = 0; i < N; ++i) {
			++B[A[i]];
		}
		vector<int> C;
		for (int i = 0; i < N; ++i) {
			if (B[A[i]] == 6) {
				C.push_back(A[i]);
			}
		}
		vector<vector<int>> D(201);
		for (int i = 0; i < C.size(); ++i) {
			D[C[i]].push_back(i + 1);
		}
		vector<iii> E;
		for (int i = 0; i < 201; ++i) {
			if (B[i] == 6) {
				E.push_back({accumulate(D[i].begin(), D[i].begin() + 4, 0), D[i][4], i});
			}
		}
		int ans = get<2>(*min_element(E.begin(), E.end()));
		cout << ans << "\n";
	}
	return 0;
}
