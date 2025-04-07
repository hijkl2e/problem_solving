#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, Q{};
	cin >> N >> M >> Q;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	ll r{}, c{};
	bool rev{};
	string out(N * (M + 1), '\n');
	while (Q--) {
		int q{};
		cin >> q;
		if (q == 1) {
			int x{}, y{};
			cin >> x >> y;
			r += (rev ? -1 : 1) * x;
			c += (rev ? -1 : 1) * y;
			rev ^= true;
			continue;
		}
		r = (r % N + N) % N;
		c = (c % M + M) % M;
		int x = (r + (rev ? N - 1 : 0)) % N;
		int y = (c + (rev ? M - 1 : 0)) % M;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				out[i * (M + 1) + j] = A[x][y];
				y += rev ? M - 1 : 1;
				y -= y >= M ? M : 0;
			}
			x += rev ? N - 1 : 1;
			x -= x >= N ? N : 0;
		}
		cout << out;
	}
	return 0;
}
