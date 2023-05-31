#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void print(ll x) {
	for (int i = 3; i >= 0; --i) {
		cout << ((x >> (8 * i)) & 255) << (i ? "." : "\n");
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (j) {
				char c{};
				cin >> c;
			}
			int x{};
			cin >> x;
			A[i] = (A[i] << 8) | x;
		}
	}
	ll addr{};
	int k = 31;
	for (; k >= 0; --k) {
		int sum{};
		for (int i = 0; i < N; ++i) {
			sum += (A[i] >> k) & 1;
		}
		if (sum == N) {
			addr |= 1LL << k;
		} else if (sum) {
			break;
		}
	}
	ll mask = (1LL << 32) - (1LL << (k + 1));
	print(addr);
	print(mask);
	return 0;
}
