#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll nCr(ll N, ll R, ll X) {
	R = min(R, N - R);
	__int128 ret = 1;
	for (int i = 1; i <= R && ret < X; ++i) {
		ret = ret * (N - R + i) / i;
	}
	if (ret > X) {
		ret = X;
	}
	return ret;
}

ll nHr(ll N, ll R, ll X) {
	return nCr(N + R - 1, R, X);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, K{}, X{};
	cin >> N >> K >> X;
	if (2 * N - 1 > K) {
		cout << "-1\n";
		return 0;
	}
	vector<int> A(N + 1, 1);
	bool odd = K % 2;
	K = (K + 1) / 2 - N;
	if (nHr(N, K, X) < X) {
		cout << "-1\n";
		return 0;
	}
	for (int i = 1; K > 0;) {
		ll val = nHr(N - i + 1, K - 1, X);
		if (X <= val) {
			++A[i];
			--K;
		} else {
			X -= val;
			++i;
		}
	}
	A[N] = 2 * A[N] - odd;
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < A[i]; ++j) {
			cout << i << " ";
		}
	}
	for (int i = N; i > 0; --i) {
		for (int j = 0; j < A[i]; ++j) {
			cout << i << (i == 1 && j == A[1] - 1 ? "\n" : " ");
		}
	}
	return 0;
}
