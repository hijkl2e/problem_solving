#include <bits/stdc++.h>

using namespace std;

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N + M + 1);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < M; ++i) {
		cin >> A[i + N + 1];
	}
	reverse(A.begin(), A.end());
	vector<int> z = get_z(A);
	vector<int> B(N + 1);
	for (int i = 0; i < N; ++i) {
		++B[i], --B[i + z[M + i + 1]];
	}
	partial_sum(B.begin(), B.end(), B.begin());
	vector<int> C;
	for (int i = 0, j = 1; i < N; i = j++) {
		if (B[i] == 0) {
			continue;
		}
		while (j < N && B[j]) {
			++j;
		}
		C.push_back(j - i);
	}
	int ans{};
	for (int x : C) {
		ans ^= x;
	}
	cout << (ans ? "First" : "Second") << "\n";
	return 0;
}
