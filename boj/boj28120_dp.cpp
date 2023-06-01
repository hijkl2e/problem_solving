#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;
using rec = tuple<int, int, vector<int>>;

int N, K, X;
vector<int> B;

int v2i() {
	int ret{};
	for (int i = K - 1; i >= 0; --i) {
		ret = (X + 1) * ret + B[i];
	}
	return ret;
}

void i2v(int x) {
	for (int i = 0; i < K; ++i) {
		B[i] = x % (X + 1);
		x /= X + 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K >> X;
	vector<rec> A(N);
	for (int i = 0; i < N; ++i) {
		get<1>(A[i]) = i + 1;
		auto &v = get<2>(A[i]);
		int C{};
		cin >> C;
		while (C--) {
			int x{};
			cin >> x;
			v.push_back(x - 1);
		}
	}
	for (int i = 0; i < N; ++i) {
		cin >> get<0>(A[i]);
	}
	sort(A.rbegin(), A.rend());
	B.resize(K);
	int sz = 1;
	for (int i = 0; i < K; ++i) {
		sz *= X + 1;
	}
	vector<iii> dp(sz, {-1, -1, -1});
	vector<int> D{0};
	for (int i = 0; i < N; ++i) {
		vector<int> E;
		for (int x : D) {
			i2v(x);
			for (int y : get<2>(A[i])) {
				if (B[y] == X) {
					continue;
				}
				++B[y];
				int z = v2i();
				if (get<0>(dp[z]) == -1) {
					dp[z] = {i, y, x};
					E.push_back(z);
				}
				--B[y];
			}
		}
		if (E.size()) {
			swap(D, E);
		}
	}
	vector<vector<int>> F(K);
	int x = D[0];
	while (x) {
		auto &[a, b, c] = dp[x];
		F[b].push_back(get<1>(A[a]));
		x = c;
	}
	for (int i = 0; i < K; ++i) {
		cout << F[i].size();
		for (int y : F[i]) {
			cout << " " << y;
		}
		cout << "\n";
	}
	return 0;
}
