#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{}, a{}, b{};
	cin >> R >> C >> a >> b;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < a; ++j) {
			for (int k = 0; k < C; ++k) {
				for (int l = 0; l < b; ++l) {
					cout << ((i + k) % 2 ? '.' : 'X');
				}
			}
			cout << "\n";
		}
	}
	return 0;
}
