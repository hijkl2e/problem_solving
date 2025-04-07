#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int k = 0; k < 5; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 5; ++j) {
				cout << string(N, (k == 0 ? j == 3 : k == 4 ? j == 1 : j % 2) ? ' ' : '@');
			}
			cout << "\n";
		}
	}
	return 0;
}
