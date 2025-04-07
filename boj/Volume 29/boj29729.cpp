#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int S{}, N{}, M{};
	cin >> S >> N >> M;
	N += M;
	int U{};
	while (N--) {
		int q{};
		cin >> q;
		if (q) {
			if (U++ == S) {
				S *= 2;
			}
		} else {
			--U;
		}
	}
	cout << S << "\n";
	return 0;
}
