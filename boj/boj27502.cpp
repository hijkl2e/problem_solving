#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, t{};
	cin >> N >> t;
	cout << "! " << N / 2 + t << endl;
	if (t) {
		cout << "1 1" << endl;
	}
	for (int i = t; i < N / 2; ++i) {
		int u{}, v{};
		cin >> u >> v;
		cout << v << " " << u << endl;
	}
	return 0;
}
