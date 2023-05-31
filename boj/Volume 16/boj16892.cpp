#include <bits/stdc++.h>

using namespace std;

vector<int> A;

int solve(int x, int t) {
	return t % 2 ? max(min(A[x - 1], A[x]), min(A[x], A[x + 1])) : max(A[x - 1], A[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	if (N == 1) {
		cout << A[0] << "\n";
		return 0;
	}
	vector<int> B(N);
	int x = N / 2, y = N % 2, z = y ^ 1;
	for (int i = 0; i < N - 2; i += 2) {
		B[i] = max({i ? B[i - 2] : 0, solve(x - i / 2, y), solve(x + i / 2, y)});
		B[i + 1] = max({i ? B[i - 1] : 0, solve(x - i / 2 - z, z), solve(x + i / 2 + y, z)});
	}
	B[N - 2] = B[N - 1] = *max_element(A.begin(), A.end());
	for (int i = 0; i < N; ++i) {
		cout << B[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
