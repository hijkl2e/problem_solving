#include <bits/stdc++.h>

using namespace std;

vector<int> A, C, D;

void solve(int s, int e, int &p) {
	if (s == e) {
		return;
	}
	int x = A[p++];
	int y = C[x];
	solve(s, y, p);
	solve(y + 1, e, p);
	D.push_back(x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		A.resize(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		vector<int> B(N);
		for (int i = 0; i < N; ++i) {
			cin >> B[i];
		}
		C.resize(N + 1);
		for (int i = 0; i < N; ++i) {
			C[B[i]] = i;
		}
		D.clear();
		int p{};
		solve(0, N, p);
		for (int i = 0; i < N; ++i) {
			cout << D[i] << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
