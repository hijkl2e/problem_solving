#include <bits/stdc++.h>

using namespace std;

int N, K, ans;
vector<int> A;

void solve(int k, vector<int> B) {
	int cnt{};
	for (int i = 0; i < N; ++i) {
		if (A[i] == B[i]) {
			++cnt;
		}
	}
	ans = max(ans, cnt);
	if (k == K) {
		return;
	}
	for (int i = 0; i < N; ++i) {
		vector<int> C = B;
		rotate(C.begin() + i, C.begin() + i + 1, C.end());
		C[N - 1] = -1;
		solve(k + 1, C);
		C = B;
		rotate(C.begin() + i, C.end() - 1, C.end());
		C[i] = -1;
		solve(k + 1, C);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	solve(0, B);
	cout << ans << "\n";
	return 0;
}
