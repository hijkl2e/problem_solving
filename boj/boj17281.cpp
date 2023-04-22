#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(9));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> A[i][j];
		}
	}
	vector<int> B(9);
	for (int i = 0; i < 9; ++i) {
		B[i] = i;
	}
	int ans{};
	do {
		swap(B[0], B[3]);
		int cnt{}, p{};
		deque<int> dq;
		for (int i = 0; i < N; ++i) {
			dq.clear();
			int out{};
			while (out < 3) {
				int x = A[i][B[p]];
				p = (p + 1) % 9;
				if (x == 0) {
					++out;
					continue;
				}
				dq.push_back(0);
				for (int &y : dq) {
					y += x;
				}
				while (dq.size() && dq[0] > 3) {
					++cnt;
					dq.pop_front();
				}
			}
		}
		ans = max(ans, cnt);
		swap(B[0], B[3]);
	} while (next_permutation(B.begin() + 1, B.end()));
	cout << ans << "\n";
	return 0;
}
