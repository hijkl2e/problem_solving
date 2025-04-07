#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> X(100001);
	vector<int> Y(100001);
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		++X[x], ++Y[y];
	}
	while (M--) {
		int x{}, y{};
		cin >> x >> y;
		--X[x], --Y[y];
	}
	bool yes = true;
	for (int i = 1; i < 100001; ++i) {
		yes &= X[i] % 2 == 0 && Y[i] % 2 == 0;
	}
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
