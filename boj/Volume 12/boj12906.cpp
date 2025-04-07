#include <bits/stdc++.h>

using namespace std;

int v2i(vector<int> &A) {
	int x{};
	for (int i = 0; i < 3; ++i) {
		int j{};
		while (A[i] >> (2 * j)) {
			++j;
		}
		x = 4 * ((x << (2 * j)) + A[i]);
	}
	x /= 4;
	return x;
}

void i2v(int x, vector<int> &A) {
	for (int i = 2; i >= 0; --i) {
		int j{};
		while ((x >> (2 * j)) & 3) {
			++j;
		}
		A[i] = x & ((1 << (2 * j)) - 1);
		x >>= 2 * (j + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	vector<int> A(3);
	vector<int> B(3);
	for (int i = 0; i < 3; ++i) {
		int K{};
		cin >> K;
		if (K) {
			string s;
			cin >> s;
			for (char c : s) {
				int x = c - 'A';
				A[i] = 4 * A[i] + (x + 1);
				B[x] = 4 * B[x] + (x + 1);
			}
			N += K;
		}
	}
	vector<int> D(1 << (2 * (N + 2)), -1);
	queue<int> q;
	int x = v2i(A);
	D[x] = 0;
	q.push(x);
	while (q.size()) {
		x = q.front(); q.pop();
		i2v(x, A);
		for (int i = 0; i < 3; ++i) {
			if (A[i] == 0) {
				continue;
			}
			for (int j = 0; j < 3; ++j) {
				if (i == j) {
					continue;
				}
				A[j] = 4 * A[j] + (A[i] & 3);
				A[i] /= 4;
				int y = v2i(A);
				if (D[y] == -1) {
					D[y] = D[x] + 1;
					q.push(y);
				}
				A[i] = 4 * A[i] + (A[j] & 3);
				A[j] /= 4;
			}
		}
	}
	x = v2i(B);
	cout << D[x] << "\n";
	return 0;
}
