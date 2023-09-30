#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, R{}, C{};
	cin >> N >> R >> C;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << ((i + j + R + C) % 2 ? '.' : 'v');
		}
		cout << "\n";
	}
	return 0;
}
