#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 1; i < N; ++i) {
		if (A[i - 1] < A[i]) {
			M = M / A[i - 1] * A[i] + M % A[i - 1];
		}
	}
	cout << M << "\n";
	return 0;
}
