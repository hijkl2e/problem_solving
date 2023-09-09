#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		char c{};
		cin >> N >> c;
		cout << string(N, c) << "\n";
	}
	return 0;
}
