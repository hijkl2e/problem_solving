#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N + 1);
	for (int i = 1; i < N; ++i) {
		cin >> A[i];
	}
	A[0] = A[1];
	A[N] = A[N - 1];
	vector<ll> B(N);
	for (int i = 0; i < N; ++i) {
		B[i] = A[i] & A[i + 1];
	}
	for (int i = N - 2; i >= 0; --i) {
		if (B[i] <= B[i + 1]) {
			continue;
		}
		int j = 59;
		for (; j >= 0; --j) {
			if ((B[i] ^ B[i + 1]) & (1LL << j)) {
				break;
			}
		}
		while (++j < 60) {
			if (B[i] & B[i + 1] & (i ? B[i - 1] : ~0) & (1LL << j)) {
				B[i] &= ~(1LL << j);
				break;
			}
		}
	}
	bool yes = true;
	for (int i = 0; i < N - 1; ++i) {
		yes &= (B[i] | B[i + 1]) == A[i + 1];
		yes &= B[i] <= B[i + 1];
	}
	if (yes) {
		cout << "Yes\n";
		for (int i = 0; i < N; ++i) {
			cout << B[i] << (i == N - 1 ? "\n" : " ");
		}
	} else {
		cout << "No\n";
	}
	return 0;
}
