#include <bits/stdc++.h>

using namespace std;

using rec = tuple<int, int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, K{}, t{}, M{};
		cin >> N >> K >> t >> M;
		vector<vector<int>> A(N + 1, vector<int>(K + 1));
		vector<int> B(N + 1);
		vector<int> C(N + 1, -1);
		for (int i = 0; i < M; ++i) {
			int a{}, b{}, c{};
			cin >> a >> b >> c;
			A[a][b] = max(A[a][b], c);
			++B[a];
			C[a] = i;
		}
		vector<rec> D;
		for (int i = 1; i <= N; ++i) {
			A[i][0] = accumulate(A[i].begin(), A[i].end(), 0);
			D.push_back({-A[i][0], B[i], C[i], i});
		}
		sort(D.begin(), D.end());
		int p{};
		while (get<3>(D[p]) != t) {
			++p;
		}
		int ans = p + 1;
		cout << ans << "\n";
	}
	return 0;
}
