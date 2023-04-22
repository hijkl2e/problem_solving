#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int S{}, N{};
		cin >> S >> N;
		while (N--) {
			int q{}, p{};
			cin >> q >> p;
			S += q * p;
		}
		cout << S << "\n";
	}
	return 0;
}
