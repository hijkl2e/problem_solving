#include <bits/stdc++.h>

using namespace std;

int N, ans;
vector<vector<int>> S;
vector<int> A, B;

int solve(vector<int> &v) {
	int ret{};
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v.size(); ++j) {
			ret += S[v[i]][v[j]];
		}
	}
	return ret;
}

void solve(int x) {
	if (x == N) {
		ans = min(ans, abs(solve(A) - solve(B)));
		return;
	}
	if (A.size() < N / 2) {
		A.push_back(x);
		solve(x + 1);
		A.pop_back();
	}
	if (B.size() < N / 2) {
		B.push_back(x);
		solve(x + 1);
		B.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	S.assign(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> S[i][j];
		}
	}
	ans = 1e9;
	A.push_back(0);
	solve(1);
	cout << ans << "\n";
	return 0;
}
