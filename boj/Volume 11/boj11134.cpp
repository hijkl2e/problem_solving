#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, C{};
		cin >> N >> C;
		cout << (N - 1) / C + 1 << "\n";
	}
	return 0;
}
