#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		for (char c : A[i]) {
			B[i] |= 1 << (c - 'a');
		}
	}
	int S = (1 << 26) - 1;
	while (M--) {
		int q{};
		char c{};
		cin >> q >> c;
		if (q == 1) {
			S &= ~(1 << (c - 'a'));
		} else {
			S |= (1 << (c - 'a'));
		}
		int ans{};
		for (int i = 0; i < N; ++i) {
			if ((B[i] & S) == B[i]) {
				++ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
