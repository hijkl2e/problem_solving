#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(11, vector<int>(10));
	fill(A[1].begin(), A[1].end(), 1);
	for (int i = 2; i < 11; ++i) {
		int sum{};
		for (int j = 0; j < 10; ++j) {
			A[i][j] = sum;
			sum += A[i - 1][j];
		}
	}
	int len = -1;
	for (int i = 1; i < 11; ++i) {
		int cnt = accumulate(A[i].begin(), A[i].end(), 0);
		if (N < cnt) {
			len = i;
			break;
		}
		N -= cnt;
	}
	if (len == -1) {
		cout << "-1\n";
		return 0;
	}
	string ans;
	for (int i = len; i > 0; --i) {
		for (int j = 0; j < 10; ++j) {
			if (N < A[i][j]) {
				ans += '0' + j;
				break;
			}
			N -= A[i][j];
		}
	}
	cout << ans << "\n";
	return 0;
}
