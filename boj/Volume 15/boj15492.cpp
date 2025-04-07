#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

vector<int> get_z(vector<int> &s) {
	int n = s.size();
	vector<int> z(n);
	int x{}, y{};
	for (int i = 1; i < n; ++i) {
		z[i] = y < i ? 0 : min(y - i + 1, z[i - x]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			++z[i];
		}
		if (i + z[i] - 1 > y) {
			x = i, y = i + z[i] - 1;
		}
	}
	return z;
}

iii solve(vector<int> &B, vector<int> &z, int n, int s) {
	int x = z[n + s];
	int res = x == n ? 0 : B[x] < B[n + s + x] ? 1 : -1;
	return {res, -res * x, B[n + s + x]};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	reverse(A.begin(), A.end());
	vector<int> B(3 * N);
	int p{};
	while (true) {
		for (int i = 0; i < 3; ++i) {
			copy(A.begin(), A.begin() + N, B.begin() + i * N);
		}
		B[N] = -1;
		vector<int> z = get_z(B);
		iii minv{1, 1, 1};
		int minp{};
		for (int i = 1; i < N; ++i) {
			if (i == p) {
				continue;
			}
			iii res = solve(B, z, N, i);
			if (minv > res) {
				minv = res;
				minp = i;
			}
		}
		if (p && get<0>(minv) > -1) {
			break;
		}
		rotate(A.begin(), A.begin() + minp, A.end());
		p = (p - minp + N) % N;
	}
	for (int i = 0; i < N; ++i) {
		cout << A[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
