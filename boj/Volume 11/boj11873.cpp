#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	while (cin >> N >> M, N) {
		cin.ignore();
		vector<vector<int>> A(N, vector<int>(M));
		for (int i = 0; i < N; ++i) {
			string s;
			getline(cin, s);
			for (int j = 0; j < M; ++j) {
				A[i][j] = s[2 * j] == '1';
			}
		}
		vector<vector<int>> B(N + 1, vector<int>(M + 1));
		for (int i = 0; i < N; ++i) {
			for (int j = M - 1; j >= 0; --j) {
				B[i][j] = A[i][j] ? B[i][j + 1] + 1 : 0;
			}
		}
		int ans{};
		for (int j = 0; j < M; ++j) {
			stack<ii> st;
			for (int i = 0; i <= N; ++i) {
				int y = i;
				while (st.size() && st.top().first > B[i][j]) {
					y = st.top().second;
					ans = max(ans, (i - y) * st.top().first);
					st.pop();
				}
				if (st.empty() || st.top().first < B[i][j]) {
					st.push({B[i][j], y});
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
