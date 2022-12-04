#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ll ans{};
	for (int i = N - 2; i >= 0; --i) {
		int x = max(A[i] - A[i + 1] + 1, 0);
		ans += x;
		A[i] -= x;
	}
	bool yes = true;
	for (int i = 0; i < N; ++i) {
		if (A[i] < 0) {
			yes = false;
			break;
		}
	}
	cout << (yes ? ans : 1) << "\n";
	return 0;
}
