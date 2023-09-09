#include <bits/stdc++.h>

using namespace std;

int solve(vector<string> &v1, vector<string> &v2) {
	int ret{};
	for (int i = 0; i < v1.size(); ++i) {
		for (int j = 0; j < v1[i].size(); ++j) {
			if (v1[i][j] != v2[i][j]) {
				++ret;
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<vector<string>> A(N, vector<string>(5));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 5; ++j) {
			getline(cin, A[i][j]);
		}
	}
	int ans_x{}, ans_y{}, ans_k = 1e9;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			int res = solve(A[i], A[j]);
			if (ans_k > res) {
				ans_x = i + 1, ans_y = j + 1;
				ans_k = res;
			}
		}
	}
	cout << ans_x << " " << ans_y << "\n";
	return 0;
}
