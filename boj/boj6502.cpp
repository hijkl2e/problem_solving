#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int r{}, w{}, l{};
	for (int tc = 1; cin >> r >> w >> l; ++tc) {
		cout << "Pizza " << tc << " ";
		cout << (w * w + l * l <= 4 * r * r ? "fits" : "does not fit");
		cout << " on the table.\n";
	}
	return 0;
}
