#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<int> X(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> X[i];
	}
	while (Q--) {
		int q{}, a{}, b{};
		cin >> q >> a >> b;
		if (q == 1) {
			X[a] = b;
		} else {
			cout << abs(X[b] - X[a]) << "\n";
		}
	}
	return 0;
}
