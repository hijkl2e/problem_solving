#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> A;
deque<bool> B;
set<int> S;

void solve(int n, int x) {
	if (n == K) {
		S.insert(x);
		return;
	}
	for (int i = 0; i < N; ++i) {
		if (B[i]) {
			continue;
		}
		int y = (A[i] < 10 ? 10 : 100) * x + A[i];
		B[i] = true;
		solve(n + 1, y);
		B[i] = false;
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
	B.resize(N);
	solve(0, 1);
	cout << S.size() << "\n";
	return 0;
}
