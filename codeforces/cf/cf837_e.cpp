#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> s1(N + 1, vector<int>(M + 1));
	vector<vector<int>> s2(N + 1, vector<int>(M + 1));
	vector<vector<int>> s3(N + 1, vector<int>(M + 1));
	vector<vector<int>> s4(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			s1[j][i] = s1[j - 1][i] + (A[j - 1][i - 1] == 'm');
			s2[j][i] = s2[j - 1][i] + (A[j - 1][i - 1] == '#');
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			s3[i][j] = s3[i][j - 1] + (A[i - 1][j - 1] == 'm');
			s4[i][j] = s4[i][j - 1] + (A[i - 1][j - 1] == '#');
		}
	}
	int ans{};
	for (int n = 0; n < 2; ++n) {
		for (int i = 1; i <= M; ++i) {
			for (int j = i + 2; j <= M; ++j) {
				for (int k = 1, l = 0, m = 1; k <= N; ++k) {
					while ((s1[k][i] - s1[l][i] + s1[k][j] - s1[l][j] > n)
							|| (s2[k][i] - s2[l][i] + s2[k][j] - s2[l][j] > 0)) {
						++l;
					}
					while (m < k && (m < l + 2 || (s3[m][j - 1] - s3[m][i] > 1 - n)
							|| (s4[m][j - 1] - s4[m][i] > 0))) {
						++m;
					}
					if (k - l > 2 && m < k) {
						ans = max(ans, 2 * (k - l) + (j - i - 1));
					}
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
