#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> grid(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, grid[i]);
	}
	vector<vector<int>> A(N, vector<int>(M + 1));
	for (int i = 0; i < N; ++i) {
		for (int j = M - 1; j >= 0; --j) {
			if (grid[i][j] == '.') {
				A[i][j] = A[i][j + 1] + 1;
			}
		}
	}
	vector<int> B(M + 1);
	for (int j = 0; j < M; ++j) {
		stack<ii> st;
		for (int i = 0; i < N; ++i) {
			int miny = i;
			while (st.size() && st.top().first > A[i][j]) {
				auto [x, y] = st.top(); st.pop();
				B[x] = max(B[x], i - y);
				miny = min(miny, y);
			}
			if (st.empty() || st.top().first < A[i][j]) {
				st.push({A[i][j], miny});
			}
		}
		while (st.size()) {
			auto [x, y] = st.top(); st.pop();
			B[x] = max(B[x], N - y);
		}
	}
	for (int i = M - 1; i > 0; --i) {
		B[i] = max(B[i], B[i + 1]);
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		int a{}, b{};
		cin >> a >> b;
		cout << (B[b] >= a ? "YES" : "NO") << "\n";
	}
	return 0;
}
