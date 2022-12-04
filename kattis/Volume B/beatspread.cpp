#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int S{}, D{};
		cin >> S >> D;
		if (S < D || (S - D) % 2) {
			cout << "impossible\n";
			continue;
		}
		S = (S - D) / 2;
		cout << S + D << " " << S << "\n";
	}
	return 0;
}
