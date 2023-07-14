#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int N, M;
vector<int> A;
int dp[301][301][2];

int solve(int x, int y, int z, int k) {
	int &ret = dp[x][y][z];
	if (ret != INF) {
		return ret;
	} else if (k == 0) {
		return ret = 0;
	}
	if (x) {
		ret = min(ret, ((z ? A[y] : A[x]) - A[x - 1]) * k + solve(x - 1, y, 0, k - 1));
	}
	if (y + 1 < N) {
		ret = min(ret, (A[y + 1] - (z ? A[y] : A[x])) * k + solve(x, y + 1, 1, k - 1));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	bool flag{};
	auto it = find(A.begin(), A.end(), 0);
	if (it == A.end()) {
		A.push_back(0);
		++N, flag = true;
	}
	sort(A.begin(), A.end());
	int x = lower_bound(A.begin(), A.end(), 0) - A.begin();
	int ans{};
	for (int i = 1; i <= N; ++i) {
		memset(dp, 0x3f, sizeof dp);
		ans = max(ans, i * M - solve(x, x, 0, i - 1));
	}
	ans -= flag ? M : 0;
	cout << ans << "\n";
	return 0;
}
