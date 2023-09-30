#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int d{}, n{}, s{}, p{};
		cin >> d >> n >> s >> p;
		int x = d + n * p;
		int y = n * s;
		if (x < y) {
			cout << "parallelize\n";
		} else if (x > y) {
			cout << "do not parallelize\n";
		} else {
			cout << "does not matter\n";
		}
	}
	return 0;
}
