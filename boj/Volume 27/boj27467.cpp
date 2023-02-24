#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, p{}, q{};
	cin >> N;
	while (N--) {
		int x{};
		cin >> x;
		if (x % 3 == 0) {
			++q;
		} else if (x % 3 == 1) {
			++p;
		} else {
			--p, --q;
		}
	}
	cout << p << " " << q << "\n";
	return 0;
}
