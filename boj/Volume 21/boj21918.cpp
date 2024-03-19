#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	while (M--) {
		int q{}, a{}, b{};
		cin >> q >> a >> b;
		if (q == 1) {
			A[a - 1] = b;
			continue;
		}
		for (int i = a - 1; i < b; ++i) {
			if (q == 2) {
				A[i] ^= 1;
			} else {
				A[i] = (q == 4);
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << A[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
