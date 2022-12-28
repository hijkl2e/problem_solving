#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int i = 0; i < 2 * N; ++i) {
		cout << (i % 2 ? " " : "");
		for (int j = i % 2; j < N; j += 2) {
			cout << "*" << (j + 2 < N ? " " : "\n");
		}
	}
	return 0;
}
