#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void sort(vector<ll> &S) {
	vector<vector<int>> A(256);
	for (int k = 0; k < 4; ++k) {
		for (int i = 0; i < 256; ++i) {
			A[i].clear();
		}
		int shift = 8 * k;
		for (int i = 0; i < S.size(); ++i) {
			A[(S[i] >> shift) & 255].push_back(S[i]);
		}
		for (int i = 0, j = 0; i < 256; ++i) {
			for (int x : A[i]) {
				S[j++] = x;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		ll A{}, B{}, C{}, X{}, Y{};
		cin >> N >> A >> B >> C >> X >> Y;
		vector<ll> S(N);
		S[0] = A;
		for (int i = 1; i < N; ++i) {
			S[i] = (S[i - 1] * B + A) % C;
		}
		sort(S);
		ll V{};
		for (int i = 0; i < N; ++i) {
			V = (V * X + S[i]) % Y;
		}
		cout << V << "\n";
	}
	return 0;
}
