#include <bits/stdc++.h>

using namespace std;

vector<int> A[6][6][6][6][6][6];
int dp[7][7][7][7][7][7];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> B(6);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 6; ++j) {
			cin >> B[j];
			--B[j];
		}
		A[B[0]][B[1]][B[2]][B[3]][B[4]][B[5]].push_back(i + 1);
		++dp[B[0]][B[1]][B[2]][B[3]][B[4]][B[5]];
	}
	vector<int> C;
	int ans = N;
	for (B[0] = 5; B[0] >= 0; --B[0])
	for (B[1] = 5; B[1] >= 0; --B[1])
	for (B[2] = 5; B[2] >= 0; --B[2])
	for (B[3] = 5; B[3] >= 0; --B[3])
	for (B[4] = 5; B[4] >= 0; --B[4])
	for (B[5] = 5; B[5] >= 0; --B[5]) {
		int &val = dp[B[0]][B[1]][B[2]][B[3]][B[4]][B[5]];
		for (int i = 1; i < 64; ++i) {
			for (int j = 0; j < 6; ++j) {
				if (i & (1 << j)) {
					++B[j];
				}
			}
			val += (__builtin_popcount(i) % 2 ? 1 : -1)
					* dp[B[0]][B[1]][B[2]][B[3]][B[4]][B[5]];
			for (int j = 0; j < 6; ++j) {
				if (i & (1 << j)) {
					--B[j];
				}
			}
		}
		auto &v = A[B[0]][B[1]][B[2]][B[3]][B[4]][B[5]];
		if (v.empty()) {
			continue;
		}
		if (ans > val) {
			ans = val;
			C.clear();
		}
		if (ans == val) {
			copy(v.begin(), v.end(), back_inserter(C));
		}
	}
	ans = N - ans;
	sort(C.begin(), C.end());
	cout << C.size() << " " << ans << "\n";
	for (int i = 0; i < C.size(); ++i) {
		cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
	}
	return 0;
}
